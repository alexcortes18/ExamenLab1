#ifndef ENEMIGO3_H
#define ENEMIGO3_H

#include "Personaje.h"
#include "Jugador.h"
#include <stdlib.h>
#include <list>
#include "Proyectil3.h"

class Jugador;
class Enemigo3 : public Enemigo
{
    public:
        Jugador* jugador;
        Enemigo3(list<Entidad*>* entidades,SDL_Renderer* renderer);
        virtual ~Enemigo3();
        void logica();
    protected:
    private:
};

#endif // ENEMIGO3_H
