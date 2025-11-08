#include "Figura.h"

using namespace System;
using namespace System::Drawing;

public ref class Circulo : public Figura
{
private:
    int radio;
public:
    Circulo(Point pos, int r, Color col, int score)
        : Figura(pos, col, score, r), radio(r) {
    }

    virtual void Dibujar(Graphics^ g) override {
        SolidBrush^ sb = gcnew SolidBrush(color);
        g->FillEllipse(sb, posicion.X, posicion.Y, radio * 2, radio * 2);


        Brush^ b = Brushes::White;

        String^ texto = scoring.ToString();
        Font^ fuente = gcnew Font("Arial", 10);
        SizeF size = g->MeasureString(texto, fuente);

        float xTexto = posicion.X + radio - size.Width / 2;
        float yTexto = posicion.Y + radio - size.Height / 2;

        g->DrawString(texto, fuente, b, xTexto, yTexto);
    }
};
