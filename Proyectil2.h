#ifndef PROYECTIL2_H
#define PROYECTIL2_H

#include "Proyectil.h"

class Proyectil2 : public Proyectil
{
    public:
        SDL_Renderer* renderer;
        list<Entidad*>* entidades;
        SDL_Texture* texture;
        SDL_Rect rect;
        string state;
        Proyectil2(list<Entidad*>* entidades,SDL_Renderer* renderer, int x, int y, string state);
        virtual ~Proyectil2();
        void dibujar();
        void logica();
    protected:
    private:
};

#endif // PROYECTIL2_H
