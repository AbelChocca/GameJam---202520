#include "TramoInterfaz.h"
#include "../Figuras/Cuadrado.h"
#include "../Figuras/Circulo.h"
#include "../Figuras/Triangulo.h"

public ref class Tramo1 : public Tramo
{
public:
    Tramo1() : Tramo(0, 30, 370, 0)
    {
        this->figuras->Add(gcnew Cuadrado(Point(320, 20), 30, 30, Color::Red, this->rand->Next(1, 3), 15));
        this->figuras->Add(gcnew Circulo(Point(320, 100), 20, Color::Blue, this->rand->Next(1, 4)));
        this->figuras->Add(gcnew Triangulo(Point(320, 200), 30, Color::DarkGreen, this->rand->Next(1, 5), 15));
    }

    void Actualizar() override {
        for each (Figura ^ f in this->figuras)
            if (f != nullptr)
                f->Mover(2, 0);
    }
    bool colisionTramo(int x, int y) override {
        return x <= 0;
    };
    bool llegoAlFinal(Figura^ entity) override {
        return entity->Posicion.X > this->posicionFinal.X;
    }
};
