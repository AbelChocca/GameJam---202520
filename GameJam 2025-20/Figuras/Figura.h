#pragma once
using namespace System;
using namespace System::Drawing;

public ref class Figura abstract
{
protected:
    Point posicion;
    Color color;
public:
    Figura(Point pos, Color col) {
        posicion = pos;
        color = col;
    }

    virtual void Dibujar(Graphics^ g) abstract;
    virtual void Mover(int dx, int dy) {
        posicion.X += dx;
        posicion.Y += dy;
    }

    property Point Posicion {
        Point get() { return posicion; }
        void set(Point value) { posicion = value; }
    }
};
