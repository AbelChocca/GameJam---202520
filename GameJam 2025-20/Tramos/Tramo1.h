#include "TramoInterfaz.h"
#include "../Figuras/Cuadrado.h"
#include "../Figuras/Circulo.h"
#include "../Figuras/Triangulo.h"

public ref class Tramo1 : public Tramo
{
public:
    Tramo1() : Tramo(3, 0, 30) // 2 figuras fijas
    {
        this->figuras[0] = gcnew Cuadrado(Point(50, 50), 30, 30, Color::Red);
        this->figuras[1] = gcnew Circulo(Point(120, 80), 20, Color::Blue);
        this->figuras[2] = gcnew Triangulo(Point(70, 20), 20, Color::Yellow);
    }

    virtual void Dibujar(Graphics^ g) override {
        for each (Figura ^ f in this->figuras)
            if (f != nullptr)
                f->Dibujar(g);
    }

    virtual void Actualizar() override {
        for each (Figura ^ f in this->figuras)
            if (f != nullptr)
                f->Mover(2, 0);
    }
};
