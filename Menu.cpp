#include "Menu.h"

Menu::Menu(SDL_Renderer* renderer,SDL_Rect rect_background,SDL_Texture *background, int *a, int *b)
{
    //ctor
    this->renderer=renderer;
    this->rect_background=rect_background;
    this->background=background;


    background= IMG_LoadTexture(renderer,"castle.png");
    SDL_QueryTexture(background, NULL, NULL,a,b);

    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = 500;
    rect_background.h = 500;

}

void Menu::dibujar(int a){
     SDL_RenderCopy(renderer, background, NULL, &rect_background);

}

Menu::~Menu()
{
    //dtor
}
