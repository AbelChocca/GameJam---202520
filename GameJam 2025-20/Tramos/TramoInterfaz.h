#pragma once
#include "../shared/ColisionArgs.h"
#include "../Figuras/Figura.h"
using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

ref class Figura; // Forward Declaration

public ref class Tramo abstract
{
protected:
    List<Figura^>^ figuras;
    Point posicionInicial;
    Point posicionFinal;
    Random^ rand;

public:
    Tramo(int initX, int initY, int endX, int endY)
    {
        this->figuras = gcnew List<Figura^>();
        this->posicionInicial = Point(initX, initY);
        this->posicionFinal = Point(endX, endY);
        this->rand = gcnew Random();
    }

    void Dibujar(Graphics^ g, Figura^ entityToColision) {
        for (int i = figuras->Count - 1; i >= 0; i--) {
            if (i >= figuras->Count) continue;
            Figura^ f = figuras[i];
            if (f == nullptr) continue;

            f->Dibujar(g);

            if (Colision(entityToColision, f, entityToColision->getRadioBox(), f->getRadioBox())) {
                entityToColision->InteraccionColision(gcnew ColisionArgs(f->getScore(), f->getColor()));
                figuras->RemoveAt(i);
                continue;
            }

            if (this->colisionTramo(f->Posicion.X, f->Posicion.Y)) {
                figuras->RemoveAt(i);
                continue;
            }
        }
    };
    bool Colision(Figura^ f1, Figura^ f2, int r1, int r2) {
        int dx = f1->Posicion.X - f2->Posicion.X;
        int dy = f1->Posicion.Y - f2->Posicion.Y;
        double distancia = Math::Sqrt(dx * dx + dy * dy);
        return distancia < (r1 + r2);
    }
    virtual void Actualizar() abstract;
    virtual bool colisionTramo(int x, int y) abstract;
    virtual bool llegoAlFinal(Figura^ entity) abstract;

    virtual void Reiniciar()
    {
        for (int i = 0; i < this->figuras->Capacity; i++)
            figuras[i] = nullptr;
    }

    // Propiedades
    property List<Figura^>^ Figuras
    {
        List<Figura^>^ get() { return figuras; }
    }

    property Point PosInicial
    {
        Point get() { return posicionInicial; }
        void set(Point value) { posicionInicial = value; }
    }
    Point getPosFinal() { return posicionFinal; }
};
