#include "Figura.h"

public ref class Cuadrado : public Figura
{
private:
    int ancho, alto;
public:
    Cuadrado(Point pos, int w, int h, Color col)
        : Figura(pos, col), ancho(w), alto(h) {
    }

    virtual void Dibujar(Graphics^ g) override {
        SolidBrush^ b = gcnew SolidBrush(color);
        g->FillRectangle(b, posicion.X, posicion.Y, ancho, alto);
    }
};
