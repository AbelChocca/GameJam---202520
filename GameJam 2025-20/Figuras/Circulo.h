#include "Figura.h"

public ref class Circulo : public Figura
{
private:
    int radio;
public:
    Circulo(Point pos, int r, Color col)
        : Figura(pos, col), radio(r) {
    }

    virtual void Dibujar(Graphics^ g) override {
        SolidBrush^ b = gcnew SolidBrush(color);
        g->FillEllipse(b, posicion.X, posicion.Y, radio * 2, radio * 2);
    }
};
