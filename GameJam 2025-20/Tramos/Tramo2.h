#pragma once

#include "Figuras/Cuadrado.h"
#include "Figuras/Circulo.h"
#include "Figuras/Triangulo.h"
#include "Tramos/TramoInterfaz.h"

using namespace System::Drawing;

public ref class Tramo2 : public Tramo // <--- CAMBIO DE NOMBRE
{
private:
    int velocidadFiguras;
    int anchoPanel;
    int alturaPanel;
    array<Color>^ coloresDisponibles;
    // 'moverHaciaDerecha' eliminado

public:
    // Constructor modificado
    Tramo2(int ancho, int alto) : Tramo(ancho / 2, alto, ancho / 2, 0) // <-- Constructor Vertical (Inicio Abajo, Fin Arriba)
    {
        this->anchoPanel = ancho;
        this->alturaPanel = alto;
        this->velocidadFiguras = 4;
        this->coloresDisponibles = gcnew array<Color>{ Color::DarkGreen, Color::Blue, Color::Red };
        // 'moverHaciaDerecha' eliminado

        CrearNuevaFigura();
        CrearNuevaFigura();
        CrearNuevaFigura();
    }

    void CrearNuevaFigura() {
        int tipoFigura = rand->Next(0, 3);
        Color nuevoColor = coloresDisponibles[rand->Next(0, coloresDisponibles->Length)];
        int nuevoScore = rand->Next(1, 5);

        // --- LÓGICA VERTICAL ---
        int posX = rand->Next(20, anchoPanel - 40);  // Posición X aleatoria
        int posY = rand->Next(-150, -50);           // Inicia ARRIBA (fuera de pantalla)
        // --- FIN LÓGICA VERTICAL ---

        switch (tipoFigura) {
        case 0: figuras->Add(gcnew Cuadrado(Point(posX, posY), 30, 30, nuevoColor, nuevoScore, 15)); break;
        case 1: figuras->Add(gcnew Circulo(Point(posX, posY), 20, nuevoColor, nuevoScore)); break;
        case 2: figuras->Add(gcnew Triangulo(Point(posX, posY), 30, nuevoColor, nuevoScore, 15)); break;
        }
    }

    // Comprueba si el jugador llegó a la meta (arriba)
    virtual bool llegoAlFinal(Figura^ entity) override {
        return entity->Posicion.Y <= this->posicionFinal.Y; // <-- Comprueba la Y
    }

    virtual void Actualizar() override {
        for each (Figura ^ f in this->figuras)
        {
            if (f != nullptr)
            {
                // --- LÓGICA VERTICAL ---
                // Mueve las figuras de Arriba hacia Abajo (Y aumenta)
                f->Mover(0, -velocidadFiguras);
                // --- FIN LÓGICA VERTICAL ---
            }
        }

        while (figuras->Count < 3) {
            CrearNuevaFigura();
        }
    }

    virtual bool colisionTramo(int x, int y) override {
        // --- LÓGICA VERTICAL ---
        // Elimina las figuras si salen por ABAJO
        return y > alturaPanel + 40;
        // --- FIN LÓGICA VERTICAL ---
    };
};