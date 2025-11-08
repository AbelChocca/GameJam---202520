#pragma once
#include "../shared/ColisionArgs.h"
using namespace System;
using namespace System::Drawing;

public ref class Figura abstract
{
protected:
    Point posicion;
    Color color;
    int radioBox;
    int scoring;
public:
    Figura(Point pos, Color col, int score, int radioBox) {
        this->posicion = pos;
        this->color = col;
        this->radioBox = radioBox;
        this->scoring = score;
    }

    virtual void Dibujar(Graphics^ g) abstract;
    virtual void InteraccionColision(ColisionArgs^ args) {};
    virtual void Mover(int dx, int dy) {
        posicion.X -= dx;
        posicion.Y -= dy;
    }

    property Point Posicion {
        Point get() { return posicion; }
        void set(Point value) { posicion = value; }
    }

    int getScore() { return this->scoring; }
    int getRadioBox() { return this->radioBox; }
    Color getColor() { return this->color; }
    void setRadioBox(int newR) { this->radioBox = newR; }
};
