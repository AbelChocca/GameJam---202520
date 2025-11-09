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
    Jugador(int x, int y) : Figura(Point(x, y), Color::White, 0, 30) {
        this->rand = gcnew Random();
        this->lados = 3;
        this->velocidad = 5;
        array<Color>^ colores = gcnew array<Color>{ Color::DarkGreen, Color::Blue, Color::Red };
        this->color = colores[this->rand->Next(0, colores->Length)];
        this->sumaDeAngulos = (lados - 2) * 180;
    }

    int getLados() { return lados; }
    int getScoring() { return scoring; }
    int getVelocidad() { return velocidad; }
    int getSumaDeAngulos() { return sumaDeAngulos; }

    void setVelocidad(int v) { velocidad = v; }
    void actualizarPunto(Point new_point) {
        this->posicion = new_point;
    }

    void moverJugador(Keys tecla) {
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

    void Dibujar(Graphics^ g) override {
        Pen^ lapiz = gcnew Pen(color, 3);
        array<Point>^ puntos = gcnew array<Point>(lados);

        double angulo = (2 * Math::PI) / lados;

        for (int i = 0; i < lados; i++) {
            double px = this->posicion.X + this->radioBox * cos(i * angulo - Math::PI / 2);
            double py = this->posicion.Y + this->radioBox * sin(i * angulo - Math::PI / 2);
            puntos[i] = Point((int)px, (int)py);
        }

        g->DrawPolygon(lapiz, puntos);

        Brush^ b = Brushes::Black;
        g->DrawString(scoring.ToString(), gcnew System::Drawing::Font("Arial", 10),
            b, (float)this->posicion.X - 8, (float)this->posicion.Y - 10);
    }
    void InteraccionColision(ColisionArgs^ args) override {
        if (args->color == this->color) {
            this->lados++;
            this->scoring += args->scoring;
        }
        else {
            if (this->lados > 3) this->lados--;
            this->scoring = (this->scoring - args->scoring < 0) ? 0 : (this->scoring - args->scoring);
        }
    }

    void resetear() {
        lados = 3;
        scoring = 0;
        sumaDeAngulos = (lados - 2) * 180;
    }
};
