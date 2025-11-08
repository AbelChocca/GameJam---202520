#pragma once
#include "Figura.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace System::Drawing;
using namespace System::Windows::Forms;

ref class Jugador : public Figura {
private:
    int lados;
    int velocidad;
    int sumaDeAngulos;
    Random^ rand;

public:
    // Constructor
    Jugador(int x, int y) : Figura(Point(x, y), Color::White, 0) {
        this->rand = gcnew Random();
        this->lados = 3;
        this->velocidad = 5;
        array<Color>^ colores = gcnew array<Color>{ Color::Yellow, Color::Blue, Color::Red };
        this->color = colores[this->rand->Next(0, colores->Length)];
        this->sumaDeAngulos = (lados - 2) * 180;
    }

    int getLados() { return lados; }
    int getScoring() { return scoring; }
    int getVelocidad() { return velocidad; }
    int getSumaDeAngulos() { return sumaDeAngulos; }

    void setVelocidad(int v) { velocidad = v; }

    void mover(Keys tecla) {
        switch (tecla) {
        case Keys::W: this->posicion.Y -= velocidad; break;
        case Keys::S: this->posicion.Y += velocidad; break;
        case Keys::A: this->posicion.X -= velocidad; break;
        case Keys::D: this->posicion.X += velocidad; break;
        }
    }

    void crecer(int score) {
        if (this->lados < 10) {
            this->lados++;
            sumaDeAngulos = (this->lados - 2) * 180;
            this->scoring += score;
        }
    }

    virtual void dibujar(Graphics^ g) override {
        Pen^ lapiz = gcnew Pen(color, 3);
        array<Point>^ puntos = gcnew array<Point>(lados);

        double angulo = (2 * Math::PI) / lados;
        int radio = 30;

        for (int i = 0; i < lados; i++) {
            double px = this->posicion.X + radio * cos(i * angulo - Math::PI / 2);
            double py = this->posicion.Y + radio * sin(i * angulo - Math::PI / 2);
            puntos[i] = Point((int)px, (int)py);
        }

        g->DrawPolygon(lapiz, puntos);

        Brush^ b = Brushes::White;
        g->DrawString(scoring.ToString(), gcnew System::Drawing::Font("Arial", 10),
            b, (float)this->posicion.X - 10, (float)this->posicion.Y - 10);
    }

    void resetear() {
        lados = 3;
        scoring = 0;
        sumaDeAngulos = (lados - 2) * 180;
    }
};
