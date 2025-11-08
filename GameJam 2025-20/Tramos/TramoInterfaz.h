#pragma once
using namespace System;
using namespace System::Drawing;

public ref class Tramo abstract
{
protected:
    array<Rectangle>^ obstaculos;
    Point posicionJugador;
public:
    Tramo() {}

    // Métodos virtuales puros (abstractos)
    virtual void Dibujar(Graphics^ g) abstract;
    virtual void Actualizar() abstract;

    // Métodos comunes opcionales
    virtual void Reiniciar() { posicionJugador = Point(0, 0); }

    // Accesores
    property Point PosJugador {
        Point get() { return posicionJugador; }
        void set(Point value) { posicionJugador = value; }
    }
};
