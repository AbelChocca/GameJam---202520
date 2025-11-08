#include "Figura.h"

public ref class Cuadrado : public Figura
{
private:
    int ancho, alto;
public:
    Cuadrado(Point pos, int w, int h, Color col, int score, int radioBox)
        : Figura(pos, col, score, radioBox), ancho(w), alto(h) {
    }

    virtual void Dibujar(Graphics^ g) override {
        SolidBrush^ b = gcnew SolidBrush(color);
        g->FillRectangle(b, posicion.X, posicion.Y, ancho, alto);

        String^ texto = scoring.ToString();
        Font^ fuente = gcnew Font("Arial", 10);
        SizeF size = g->MeasureString(texto, fuente);

        float xTexto = posicion.X + ancho / 2 - size.Width / 2;
        float yTexto = posicion.Y + alto / 2 - size.Height / 2;

        g->DrawString(texto, fuente, Brushes::White, xTexto, yTexto);
    }
};
