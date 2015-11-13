#ifndef MENU_H
#define MENU_H


#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<list>
class Menu
{
    public:
        SDL_Renderer* renderer;
        SDL_Rect rect_background;
        SDL_Texture *background;
        Menu(SDL_Renderer* renderer,SDL_Rect rect_background,SDL_Texture *background,int *a,int *b);

        void dibujar(int a);
        virtual ~Menu();
    protected:
    private:
};

#endif // MENU_H
