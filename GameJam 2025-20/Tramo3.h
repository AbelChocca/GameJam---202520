#pragma once

#include "Figuras/Cuadrado.h"
#include "Figuras/Circulo.h"
#include "Figuras/Triangulo.h"
#include "Tramos/TramoInterfaz.h"

using namespace System::Drawing;

public ref class Tramo3 : public Tramo
{
private:
    int velocidadFiguras;
    int anchoPanel;
    int alturaPanel;
    array<Color>^ coloresDisponibles;
    bool moverHaciaDerecha;

public:
    Tramo3(int ancho, int alto, bool moverDerecha) : Tramo(0, 0)
    {
        this->anchoPanel = ancho;
        this->alturaPanel = alto;
        this->velocidadFiguras = 4;
        this->coloresDisponibles = gcnew array<Color>{ Color::DarkGreen, Color::Blue, Color::Red };
        this->moverHaciaDerecha = moverDerecha;

        CrearNuevaFigura();
        CrearNuevaFigura();
        CrearNuevaFigura();
    }

    void CrearNuevaFigura() {
        int tipoFigura = rand->Next(0, 3);
        Color nuevoColor = coloresDisponibles[rand->Next(0, coloresDisponibles->Length)];
        int nuevoScore = rand->Next(1, 5);
        int posY = rand->Next(20, alturaPanel - 40);

        int posX;
        if (moverHaciaDerecha) {
            posX = rand->Next(-150, -50);
        }
        else {
            posX = anchoPanel + rand->Next(50, 150);
        }

        switch (tipoFigura) {
        case 0: figuras->Add(gcnew Cuadrado(Point(posX, posY), 30, 30, nuevoColor, nuevoScore, 15)); break;
        case 1: figuras->Add(gcnew Circulo(Point(posX, posY), 20, nuevoColor, nuevoScore)); break;
        case 2: figuras->Add(gcnew Triangulo(Point(posX, posY), 30, nuevoColor, nuevoScore, 15)); break;
        }
    }

    virtual void Actualizar() override {
        for each (Figura ^ f in this->figuras)
        {
            if (f != nullptr)
            {
                if (moverHaciaDerecha)
                    f->Mover(-velocidadFiguras, 0);
                else
                    f->Mover(velocidadFiguras, 0);
            }
        }

        while (figuras->Count < 3) {
            CrearNuevaFigura();
        }
    }

    virtual bool colisionTramo(int x, int y) override {
        if (moverHaciaDerecha)
            return x > anchoPanel + 40;
        else
            return x < -40;
    };
};