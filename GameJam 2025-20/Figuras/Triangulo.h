#pragma once
#include "Figura.h"

public ref class Triangulo : public Figura
{
private:
    int tamaño;
public:
    Triangulo(Point pos, int t, Color col, int score, int radioBox)
        : Figura(pos, col, score, radioBox), tamaño(t) {
    }
    virtual void Dibujar(Graphics^ g) override {
        SolidBrush^ b = gcnew SolidBrush(color);
        array<Point>^ puntos = {
            Point(posicion.X, posicion.Y + tamaño),
            Point(posicion.X + tamaño / 2, posicion.Y),
            Point(posicion.X + tamaño, posicion.Y + tamaño)
        };
        g->FillPolygon(b, puntos);

        String^ texto = scoring.ToString();
        Font^ fuente = gcnew Font("Arial", 10);
        SizeF size = g->MeasureString(texto, fuente);

        float xTexto = posicion.X + tamaño / 2 - size.Width / 2;
        float yTexto = posicion.Y + tamaño * 2 / 3 - size.Height / 2;
        g->DrawString(texto, fuente, Brushes::White, xTexto, yTexto);
    }

};
