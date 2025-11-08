#pragma once
#include "Figuras/Jugador.h"
#include "Tramos/Tramo1.h"

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
		Jugador^ jugador;
		Tramo^ tramoActual;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label1;
		   Random^ rand;
	public:
		Carrera(bool esAutomatico)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->esAutomatico = esAutomatico;
			this->timerJuego = gcnew Timer();
			this->timerJuego->Interval = 30;
			this->KeyPreview = true;
			this->KeyDown += gcnew KeyEventHandler(this, &Carrera::Carrera_KeyDown);
			this->jugador = gcnew Jugador(25, this->panel2->Height / 2);
			this->tramoActual = gcnew Tramo1();

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
		System::ComponentModel::Container ^components;

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
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: void Carrera_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		jugador->moverJugador(e->KeyCode);
	}
	private: void DibujarJuego()
	{
		Graphics^ g = panel2->CreateGraphics();
		g->Clear(Color::White);

		if (tramoActual != nullptr)
			tramoActual->Dibujar(g, this->jugador);
		if (jugador != nullptr)
			jugador->Dibujar(g);

		delete g;
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
	void GameLoop(Object^ sender, EventArgs^ e)
	{
		if (jugador != nullptr)
			LimitarJugador();

		if (tramoActual != nullptr)
			tramoActual->Actualizar();

		DibujarJuego();
	}
	}; 
}
