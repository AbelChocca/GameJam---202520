#include "TramoInterfaz.h"
#include "../Figuras/Cuadrado.h"
#include "../Figuras/Circulo.h"
#include "../Figuras/Triangulo.h"

public ref class Tramo1 : public Tramo
{
public:
    Tramo1(int anchoPanel, int alturaPanel, Color colorTramo) : Tramo(anchoPanel, alturaPanel, 0, 30, 370, 0, colorTramo)
    {
        CrearNuevaFigura();
        CrearNuevaFigura();
        CrearNuevaFigura();
    }

    void CrearNuevaFigura() override {
        int tipoFigura = rand->Next(0, 3);
        Color nuevoColor = coloresDisponibles[rand->Next(0, coloresDisponibles->Length)];
        int nuevoScore = rand->Next(1, 5);
        int posY = rand->Next(20, alturaPanel - 40);

        int posX;
        posX = anchoPanel + rand->Next(50, 150);

        switch (tipoFigura) {
        case 0: figuras->Add(gcnew Cuadrado(Point(posX, posY), 30, 30, nuevoColor, nuevoScore, 15)); break;
        case 1: figuras->Add(gcnew Circulo(Point(posX, posY), 20, nuevoColor, nuevoScore)); break;
        case 2: figuras->Add(gcnew Triangulo(Point(posX, posY), 30, nuevoColor, nuevoScore, 15)); break;
        }
    }

    void Actualizar() override {
        for each (Figura ^ f in this->figuras)
            if (f != nullptr)
                f->Mover(2, 0);

        while (this->figuras->Count < 3) this->CrearNuevaFigura();
    }
    bool colisionTramo(int x, int y) override {
        return x <= 0;
    };
    bool llegoAlFinal(Figura^ entity) override {
        return entity->Posicion.X > this->posicionFinal.X;
    }
};
