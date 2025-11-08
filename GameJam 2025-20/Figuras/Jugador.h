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
    int scoring;
    int sumaDeAngulos;
    Color color;
    Random^ rand;

public:
    // Constructor
    Jugador(int x, int y) : Figura(x, y) {
        this->rand = gcnew Random();
        this->lados = 3;
        this->velocidad = 5;
        this->scoring = 0;
        array<Color>^ colores = gcnew array<Color>{ Color::Yellow, Color::Blue, Color::Red };
        this->sumaDeAngulos = (lados - 2) * 180;
    }

    int getLados() { return lados; }
    int getScoring() { return scoring; }
    int getVelocidad() { return velocidad; }
    int getSumaDeAngulos() { return sumaDeAngulos; }

    void setVelocidad(int v) { velocidad = v; }

    void mover(Keys tecla) {
        switch (tecla) {
        case Keys::W: y -= velocidad; break;
        case Keys::S: y += velocidad; break;
        case Keys::A: x -= velocidad; break;
        case Keys::D: x += velocidad; break;
        }
    }

    // Crecer al comer una figura
    void crecer() {
        if (lados < 10) {
            lados++;
            sumaDeAngulos = (lados - 2) * 180;
            scoring += 10; // suma puntos al crecer
        }
    }

    // Dibujar figura del jugador (según cantidad de lados)
    virtual void dibujar(Graphics^ g) override {
        Pen^ lapiz = gcnew Pen(color, 3);
        array<Point>^ puntos = gcnew array<Point>(lados);

        double angulo = (2 * Math::PI) / lados;
        int radio = 30;

        for (int i = 0; i < lados; i++) {
            double px = x + radio * cos(i * angulo - Math::PI / 2);
            double py = y + radio * sin(i * angulo - Math::PI / 2);
            puntos[i] = Point((int)px, (int)py);
        }

        g->DrawPolygon(lapiz, puntos);

        // Mostrar scoring en el centro
        Brush^ b = Brushes::White;
        g->DrawString(scoring.ToString(), gcnew System::Drawing::Font("Arial", 10),
            b, (float)x - 10, (float)y - 10);
    }

    void resetear() {
        lados = 3;
        scoring = 0;
        sumaDeAngulos = (lados - 2) * 180;
    }
};
