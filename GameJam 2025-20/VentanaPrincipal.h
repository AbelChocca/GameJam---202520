#pragma once
#include "Carrera.h"

namespace GameJam202520 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de VentanaPrincipal
	/// </summary>
	public ref class VentanaPrincipal : public System::Windows::Forms::Form
	{
	public:
		VentanaPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~VentanaPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ JUGAR;
	private: System::Windows::Forms::Button^ button2;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(VentanaPrincipal::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->JUGAR = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(55, 37);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(191, 107);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// JUGAR
			// 
			this->JUGAR->BackColor = System::Drawing::Color::DarkGreen;
			this->JUGAR->ForeColor = System::Drawing::Color::White;
			this->JUGAR->Location = System::Drawing::Point(96, 162);
			this->JUGAR->Name = L"JUGAR";
			this->JUGAR->Size = System::Drawing::Size(112, 37);
			this->JUGAR->TabIndex = 1;
			this->JUGAR->Text = L"JUGAR";
			this->JUGAR->Click += gcnew System::EventHandler(this, &VentanaPrincipal::JUGAR_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Blue;
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(95, 217);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 33);
			this->button2->TabIndex = 2;
			this->button2->Text = L"AUTOMATICO";
			this->button2->Click += gcnew System::EventHandler(this, &VentanaPrincipal::button2_Click);
			// 
			// VentanaPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->JUGAR);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"VentanaPrincipal";
			this->Text = L"VentanaPrincipal";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void JUGAR_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	};
}
