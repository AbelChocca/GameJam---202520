#pragma once
using namespace System;
using namespace System::Drawing;

ref class Figura; // Forward Declaration

public ref class Tramo abstract
{
protected:
    array<Figura^>^ figuras;
    Point posicionInicial;

public:
    Tramo(int cantidadFiguras, int initX, int initY)
    {
        this->figuras = gcnew array<Figura^>(cantidadFiguras);
        this->posicionInicial = Point(initX, initY);
    }

    virtual void Dibujar(Graphics^ g) abstract;
    virtual void Actualizar() abstract;

    virtual void Reiniciar()
    {
        for (int i = 0; i < figuras->Length; i++)
            figuras[i] = nullptr;
    }

    // Propiedades
    property array<Figura^>^ Figuras
    {
        array<Figura^>^ get() { return figuras; }
    }

    property Point PosInicial
    {
        Point get() { return posicionInicial; }
        void set(Point value) { posicionInicial = value; }
    }
};
