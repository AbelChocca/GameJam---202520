#pragma once
#include "Figuras/Jugador.h"
#include "Tramos/Tramo1.h"
#include "../GameJam 2025-20/Tramos/Tramo2.h"
#include "Tramo3.h" // Incluido desde la raíz

namespace GameJam202520 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Carrera
	/// </summary>
	public ref class Carrera : public System::Windows::Forms::Form
	{
	private:
		bool esAutomatico;
		Timer^ timerJuego;
		Bitmap^ minimapaBase;
		Jugador^ jugador;
		Tramo^ tramoActual;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label1;
		   Random^ rand;

	private: System::Windows::Forms::Label^ lblLados;
	private: System::Windows::Forms::Label^ lblPuntaje;
	private: System::Windows::Forms::Label^ lblAngulos;
	private: System::Windows::Forms::Label^ lblVelocidad;

	private:
		System::Collections::Generic::List<Tramo^>^ listaTramos;
		int tramoIndex;
		array<Color>^ coloresTramos;
	private:
			int autoMoveCounter;    // Contador para el movimiento aleatorio
			int autoMoveVertical;   // -1=Arriba, 0=Quieto, 1=Abajo
			int autoMoveHorizontal; // -1=Izquierda, 0=Quieto, 1=Derecha
	public:
		Carrera(bool esAutomatico)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->esAutomatico = esAutomatico;
			this->rand = gcnew Random();
			this->autoMoveCounter = 0;
			this->autoMoveVertical = -1;
			this->autoMoveHorizontal = 1; 
			this->timerJuego = gcnew Timer();
			this->timerJuego->Interval = 30;
			this->KeyPreview = true;
			this->KeyDown += gcnew KeyEventHandler(this, &Carrera::Carrera_KeyDown);

			this->jugador = gcnew Jugador(25, this->panel2->Height / 2);

			this->coloresTramos = gcnew array<Color>{
				Color::LightBlue, 
					Color::Green,     
					Color::Orange     
			};

			this->listaTramos = gcnew System::Collections::Generic::List<Tramo^>();
			this->tramoIndex = 0;

			this->listaTramos->Add(gcnew Tramo1(this->panel2->Width, this->panel2->Height, Color::LightBlue)); 
			this->listaTramos->Add(gcnew Tramo2(panel2->Width, panel2->Height, Color::Green));
			this->listaTramos->Add(gcnew Tramo3(panel2->Width, panel2->Height, true, Color::Orange));

			this->tramoActual = this->listaTramos[this->tramoIndex];

			this->minimapaBase = gcnew Bitmap(this->panel1->Width, this->panel1->Height);
			Graphics^ gBase = Graphics::FromImage(this->minimapaBase);

			Pen^ borderPen = gcnew Pen(Color::Black, 2);
			SolidBrush^ brushT1 = gcnew SolidBrush(this->coloresTramos[0]);
			SolidBrush^ brushT2 = gcnew SolidBrush(this->coloresTramos[1]);
			SolidBrush^ brushT3 = gcnew SolidBrush(this->coloresTramos[2]);

			Rectangle rectT1 = Rectangle(90, 210, 65, 30);
			Rectangle rectT2 = Rectangle(120, 80, 35, 90);
			Rectangle rectT3 = Rectangle(90, 40, 65, 30);

			gBase->FillRectangle(brushT1, rectT1);
			gBase->FillRectangle(brushT2, rectT2);
			gBase->FillRectangle(brushT3, rectT3);

			gBase->DrawRectangle(borderPen, rectT1);
			gBase->DrawRectangle(borderPen, rectT2);
			gBase->DrawRectangle(borderPen, rectT3);

			// Limpieza
			delete gBase;
			delete borderPen;
			delete brushT1; delete brushT2; delete brushT3;

			this->timerJuego->Tick += gcnew EventHandler(this, &Carrera::GameLoop);
			this->timerJuego->Start();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Carrera()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel1->Location = System::Drawing::Point(375, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(185, 266);
			this->panel1->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(375, 266);
			this->panel2->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Swis721 Blk BT", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(54, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Minimapa";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label1->Click += gcnew System::EventHandler(this, &Carrera::label1_Click);
			// 
			// Carrera
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(560, 266);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"Carrera";
			this->Text = L"Carrera";

			// 
			// lblLados
			// 
			this->lblLados = (gcnew System::Windows::Forms::Label());
			this->lblLados->AutoSize = true;
			this->lblLados->Font = (gcnew System::Drawing::Font(L"Arial", 9.0F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblLados->Location = System::Drawing::Point(15, 100);
			this->lblLados->Name = L"lblLados";
			this->lblLados->Size = System::Drawing::Size(48, 15);
			this->lblLados->Text = L"Lados: 0";
			this->panel1->Controls->Add(this->lblLados);
			// 
			// lblPuntaje
			// 
			this->lblPuntaje = (gcnew System::Windows::Forms::Label());
			this->lblPuntaje->AutoSize = true;
			this->lblPuntaje->Font = (gcnew System::Drawing::Font(L"Arial", 9.0F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblPuntaje->Location = System::Drawing::Point(15, 120);
			this->lblPuntaje->Name = L"lblPuntaje";
			this->lblPuntaje->Size = System::Drawing::Size(58, 15);
			this->lblPuntaje->Text = L"Puntaje: 0";
			this->panel1->Controls->Add(this->lblPuntaje);
			// 
			// lblAngulos
			// 
			this->lblAngulos = (gcnew System::Windows::Forms::Label());
			this->lblAngulos->AutoSize = true;
			this->lblAngulos->Font = (gcnew System::Drawing::Font(L"Arial", 9.0F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblAngulos->Location = System::Drawing::Point(15, 140);
			this->lblAngulos->Name = L"lblAngulos";
			this->lblAngulos->Size = System::Drawing::Size(62, 15);
			this->lblAngulos->Text = L"Ángulos: 0°";
			this->panel1->Controls->Add(this->lblAngulos);
			// 
			// lblVelocidad
			// 
			this->lblVelocidad = (gcnew System::Windows::Forms::Label());
			this->lblVelocidad->AutoSize = true;
			this->lblVelocidad->Font = (gcnew System::Drawing::Font(L"Arial", 9.0F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblVelocidad->Location = System::Drawing::Point(15, 160);
			this->lblVelocidad->Name = L"lblVelocidad";
			this->lblVelocidad->Size = System::Drawing::Size(72, 15);
			this->lblVelocidad->Text = L"Velocidad: 0";
			this->panel1->Controls->Add(this->lblVelocidad);

			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: void Carrera_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (esAutomatico) return;

		jugador->moverJugador(e->KeyCode);
	}

		   void DibujarJugadorEnMinimapa(Graphics^ g, Point entityPoint)
		   {
			   int iconSize = 10;
			   SolidBrush^ playerBrush = gcnew SolidBrush(jugador->getColor());

			   // Rectángulo del tramo actual en el minimapa
			   Rectangle rectT1 = Rectangle(90, 210, 65, 30);
			   Rectangle rectT2 = Rectangle(120, 80, 35, 90);
			   Rectangle rectT3 = Rectangle(90, 40, 65, 30);

			   Rectangle rectTramoActual;
			   if (this->tramoIndex == 0) rectTramoActual = rectT1;
			   else if (this->tramoIndex == 1) rectTramoActual = rectT2;
			   else rectTramoActual = rectT3;

			   // Calcular posición proporcional del jugador dentro del panel
			   double relX = (double)entityPoint.X / panel2->Width;
			   double relY = (double)entityPoint.Y / panel2->Height;

			   // Escalar a las coordenadas del rectángulo del minimapa
			   int iconX = rectTramoActual.X + (int)(relX * (rectTramoActual.Width - iconSize));
			   int iconY = rectTramoActual.Y + (int)(relY * (rectTramoActual.Height - iconSize));

			   g->FillEllipse(playerBrush, iconX, iconY, iconSize, iconSize);
			   delete playerBrush;
		   }


	private:
		void DibujarJuego()
	{
		Graphics^ gJuego = panel2->CreateGraphics();

		if (tramoActual != nullptr)
			gJuego->Clear(this->tramoActual->getColorTramo());
		else
			gJuego->Clear(Color::White);

		if (tramoActual != nullptr)
			tramoActual->Dibujar(gJuego, this->jugador);
		if (jugador != nullptr)
			jugador->Dibujar(gJuego);

		delete gJuego;


		Graphics^ gMinimapa = panel1->CreateGraphics();

		gMinimapa->DrawImage(this->minimapaBase, 0, 0);

		gMinimapa->DrawString(label1->Text, label1->Font, Brushes::Black, Point(54, 9));

		DibujarJugadorEnMinimapa(gMinimapa, this->jugador->Posicion);

		delete gMinimapa;



		if (jugador != nullptr)
		{
			lblLados->Text = "Lados: " + jugador->getLados();
			lblPuntaje->Text = "Puntaje: " + jugador->getScoring();
			lblAngulos->Text = "Ángulos: " + jugador->getSumaDeAngulos() + "°";
			lblVelocidad->Text = "Velocidad: " + jugador->getVelocidad();
		}

	}

		   void LimitarJugador()
		   {
			   if (jugador->Posicion.X < 0)
				   jugador->Posicion = Point(0, jugador->Posicion.Y);
			   else if (jugador->Posicion.X > panel2->Width)
				   jugador->Posicion = Point(panel2->Width, jugador->Posicion.Y);

			   if (jugador->Posicion.Y < 0)
				   jugador->Posicion = Point(jugador->Posicion.X, 0);
			   else if (jugador->Posicion.Y > panel2->Height)
				   jugador->Posicion = Point(jugador->Posicion.X, panel2->Height);
		   }

		   void AvanzarSiguienteTramo()
		   {
			   this->tramoIndex++;
			   if (this->tramoIndex >= this->listaTramos->Count) {
				   this->timerJuego->Stop();
				   this->tramoActual = nullptr;
			   }

			   while (this->tramoIndex < this->listaTramos->Count &&
				   this->listaTramos[this->tramoIndex] == nullptr) {
				   this->tramoIndex++;
			   }

			   if (this->tramoIndex < this->listaTramos->Count) {
				   this->tramoActual = this->listaTramos[this->tramoIndex];
				   this->jugador->actualizarPunto(this->tramoActual->PosInicial);
				   MessageBox::Show(this,
					   "!Felicidades pasarás al siguiente tramo",
					   "Cambio de tramo",
					   MessageBoxButtons::OK,
					   MessageBoxIcon::Information);
				   return;
			   }
			   else {
				   this->timerJuego->Stop();
				   this->tramoActual = nullptr;
			   }
		   }

		   void GameLoop(Object^ sender, EventArgs^ e)
		   {
			   if (esAutomatico && jugador != nullptr)
			   {
				   autoMoveCounter++;
				   int velocidad = jugador->getVelocidad();

				   if (autoMoveCounter > 50)
				   {
					   autoMoveCounter = 0;
					   autoMoveVertical = rand->Next(-1, 2);
					   autoMoveHorizontal = rand->Next(-1, 2);
				   }

				   int nuevaX = jugador->Posicion.X + (autoMoveHorizontal * velocidad);
				   int nuevaY = jugador->Posicion.Y + (autoMoveVertical * velocidad);

				   jugador->Posicion = Point(nuevaX, nuevaY);
			   }


			   if (jugador != nullptr)
				   LimitarJugador();

			   if (tramoActual == nullptr)
				   return;


			   if (this->tramoIndex == 2)
			   {
				   if (jugador->getLados() >= 10)
				   {
					   this->timerJuego->Stop();
					   this->tramoActual = nullptr;
					   MessageBox::Show(this,
						   "!Felicidades Ganaste PoliDashRunner!",
						   "Victoria",
						   MessageBoxButtons::OK,
						   MessageBoxIcon::Information);
					   this->Close();
					   return;
				   }
			   }
			   else if (this->tramoActual->llegoAlFinal(this->jugador))
			   {
				   if (this->tramoIndex + 1 >= this->listaTramos->Count)
				   {
					   if (jugador->getLados() >= 10) {
						   // GANAR
						   this->timerJuego->Stop();
						   this->tramoActual = nullptr;
						   MessageBox::Show(this, "!Felicidades Ganaste PoliDashRunner!", "Victoria", MessageBoxButtons::OK, MessageBoxIcon::Information);
						   this->Close();
						   return;
					   }
					   else if (jugador->getLados()>=1) {
						   // PERDER
						   this->timerJuego->Stop();
						   MessageBox::Show(this, "Perdiste ;(", "vuelve a intentarlo", MessageBoxButtons::OK, MessageBoxIcon::Information);
						   this->Close();
						   return;
					   }
				   }

				   this->AvanzarSiguienteTramo();
			   }

			   if (tramoActual != nullptr)
				   tramoActual->Actualizar();
			   
			   DibujarJuego();
		   }};
}