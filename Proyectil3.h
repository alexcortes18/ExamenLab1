#ifndef PROYECTIL3_H
#define PROYECTIL3_H

#include "Proyectil.h"

class Proyectil3 : public Proyectil
{
    public:
        SDL_Renderer* renderer;
        list<Entidad*>* entidades;
        SDL_Texture* texture;
        SDL_Rect rect;
        string state;
        Proyectil3(list<Entidad*>* entidades,SDL_Renderer* renderer, int x, int y, string state);
        virtual ~Proyectil3();
        void dibujar();
        void logica();
    protected:
    private:
};

#endif // PROYECTIL3_H
