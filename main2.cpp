
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character,*dragon;
SDL_Rect rect_background,rect_character,rect_dragon;



int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 500/*WIDTH*/, 250/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
     background = IMG_LoadTexture(renderer,"fondo.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0; rect_background.y = 0; rect_background.w = w; rect_background.h = h;

    character = IMG_LoadTexture(renderer, "personaje.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character.x = 0; rect_character.y = 100; rect_character.w = w; rect_character.h = h;

    dragon = IMG_LoadTexture(renderer, "dragon4.png");
      SDL_QueryTexture(dragon, NULL, NULL, &w, &h);
    rect_dragon.x = 0; rect_dragon.y = 200; rect_dragon.w = w; rect_dragon.h = h;
    bool flag=true;
    //Main Loop
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_RIGHT)
                    rect_character.x++;
                if(Event.key.keysym.sym == SDLK_LEFT)
                    rect_character.x--;
                if(Event.key.keysym.sym == SDLK_UP)
                    rect_character.y--;
                if(Event.key.keysym.sym == SDLK_DOWN)
                    rect_character.y++;
                    //dragon
                if(Event.key.keysym.sym == SDLK_d)
                    rect_dragon.x++;
                if(Event.key.keysym.sym == SDLK_a)
                    rect_dragon.x--;
                if(Event.key.keysym.sym == SDLK_w)
                    rect_dragon.y--;
                if(Event.key.keysym.sym == SDLK_s)
                    rect_dragon.y++;
                if(Event.key.keysym.sym == SDLK_SPACE){
                    if(flag){
                    dragon = IMG_LoadTexture(renderer, "dragon3bw.png");
                    flag=false;
                    }else{
                    dragon = IMG_LoadTexture(renderer, "dragon4.png");
                    flag=true;
                    }
                }
            }
        }


    }

	return 0;
}
