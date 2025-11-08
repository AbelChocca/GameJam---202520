#include "Figura.h"

public ref class Triangulo : public Figura
{
private:
    int tamaño;
public:
    Triangulo(Point pos, int t, Color col)
        : Figura(pos, col), tamaño(t) {
    }

    virtual void Dibujar(Graphics^ g) override {
        SolidBrush^ b = gcnew SolidBrush(color);
        array<Point>^ puntos = {
            Point(posicion.X, posicion.Y + tamaño),
            Point(posicion.X + tamaño / 2, posicion.Y),
            Point(posicion.X + tamaño, posicion.Y + tamaño)
        };
        g->FillPolygon(b, puntos);
    }
};
