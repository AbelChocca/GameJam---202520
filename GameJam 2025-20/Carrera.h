#pragma once
#include "Tramos/TramoInterfaz.h"
#include "Figuras/Jugador.h"

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
		Panel^ panelJuego;
		Random^ rand;
	public:
		Carrera(bool esAutomatico)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->esAutomatico = esAutomatico;
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
			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(300,300);
			this->Text = L"Carrera";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		}
#pragma endregion
	};
}
