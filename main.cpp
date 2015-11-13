
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<list>
#include <fstream>

#include "Jugador.h"
#include "Enemigo.h"
#include "Enemigo2.h"
#include "Enemigo3.h"
#include "Proyectil.h"

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character,*menu,*pausa;
SDL_Rect rect_background,rect_character,rect_menu,rect_pausa;

//juego es 0 para menu, 2 para juego
//3 para menu
//la a maneja el menu
//pause maneja la imagen de la pausa
//p es para parar todo con el while
int juego=0;
int a=1;
int screen=1;
int p=0;
int pause=0;

using namespace std;

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

    menu = IMG_LoadTexture(renderer,"menu1.png");
    SDL_QueryTexture(menu, NULL, NULL, &w, &h);
    rect_menu.x = 0;
    rect_menu.y = 0;
    rect_menu.w = w;
    rect_menu.h = h;

    pausa = IMG_LoadTexture(renderer,"pause1.png");
    SDL_QueryTexture(pausa, NULL, NULL, &w, &h);
    rect_pausa.x = 0;
    rect_pausa.y = 0;
    rect_pausa.w = w;
    rect_pausa.h = h;

    background = IMG_LoadTexture(renderer,"fondo.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;

    character = IMG_LoadTexture(renderer, "personaje.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character.x = 0;
    rect_character.y = 100;
    rect_character.w = w;
    rect_character.h = h;

    SDL_Texture* otro_personaje = IMG_LoadTexture(renderer,"otropersonaje.png");
    SDL_Rect otro_rect;
    otro_rect.x=150;
    otro_rect.y=50;
    otro_rect.w=32;
    otro_rect.h=32;


    list<Entidad*>entidades;
    entidades.push_back(new Jugador(&entidades,renderer));
    entidades.push_back(new Enemigo(&entidades,renderer));
    entidades.push_back(new Enemigo(&entidades,renderer));
    entidades.push_back(new Enemigo2(&entidades,renderer));
    entidades.push_back(new Enemigo2(&entidades,renderer));
    entidades.push_back(new Enemigo3(&entidades,renderer));

//    entidades.push_back(new Enemigo(&entidades,renderer));
//    entidades.push_back(new Enemigo(&entidades,renderer));
//    entidades.push_back(new Enemigo(&entidades,renderer));
//    entidades.push_back(new Enemigo(&entidades,renderer));

    double last_frame=0;
    //Main Loop
    while(true)
    {

        //Manejo de el keyboard en general
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_d)
                    if(Event.key.keysym.sym == SDLK_d)
                        rect_character.x++;


                if(Event.key.keysym.sym == SDLK_e&&juego!=0)
                {
                    //pone la pausa
                    juego=3;
                }
                if(Event.key.keysym.sym == SDLK_s)
                {
                    //maneja el estado de la pausa y menu
                    //a para menu p para pause
                    pause=1;
                    a++;
                    if(a>4)
                        a=1;
                }

                if(Event.key.keysym.sym == SDLK_p)
                {
                    if(p==0)
                    {
                        while(p==0)
                        {

                            while(SDL_PollEvent(&Event))
                            {
                                if(Event.type == SDL_QUIT)
                                {
                                    return 0;
                                }
                                if(Event.type == SDL_KEYDOWN)
                                {
                                    if(Event.key.keysym.sym == SDLK_p)
                                        p++;
                                }
                            }
                        }
                        p=0;
                    }

                }
                if(Event.key.keysym.sym == SDLK_w)
                {
                    //igul que la s pero alrevez
                    pause=0;
                    a--;
                    if(a<1)
                        a=4;
                }

                if(Event.key.keysym.sym == SDLK_SPACE)
                {
                    //dependiendo si es menu o pausa que hacer al dar space
                    //son las diferentes posiciones del switch
                    if(juego==0)
                    {
                        if(a==1)
                        {
                            //borrar todo en los archivos para que cargue un nuevo game

                            ofstream out("Posiciones");
                            ofstream out2("Estado");


                            out<<200<<' ';
                            out<<150<<' ';
                            out2<<"down"<<' ';

                            out.close();
                            out2.close();



//                            std::ofstream ofs;
//                            ofs.open("Posiciones", std::ofstream::out | std::ofstream::trunc);
//                            ofs.close();
//
//                            std::ofstream ofs2;
//                            ofs2.open("Estado", std::ofstream::out | std::ofstream::trunc);
//                            ofs2.close();
//
//                            remove("\progra-doug-alex\labprogra3\Estado");
//                            remove("\progra-doug-alex\labprogra3\Posiciones");

                            juego=2;
                        }
                        if(a==2)
                        {
                            cout<<a;
                            juego=2;
                        }
                        if(a==4)
                        {
                            exit(0);
                        }
                        if(a==3)
                        {
                            screen++;
                            if(screen>3)
                            {
                                screen=1;
                                SDL_SetWindowFullscreen(window,0);
                            }
                            switch(screen)
                            {
                            case 1:
                                SDL_SetWindowSize(window,500,250);
                                break;
                            case 2:
                                SDL_SetWindowSize(window,1000,500);
                                break;
                            case 3:
                                SDL_SetWindowFullscreen(window,1);
                                break;
                            }


                        }
                    }

                    if(juego==3)
                    {

                        if(pause==0)
                        {
                            juego=2;
                        }
                        if(pause==1)
                        {
                            exit(0);
                        }

                    }

                }
            }

        }

        if(juego==0)
        {
            //este es el menu
            // y todo su movimiento en el menu

            while(SDL_PollEvent(&Event))
            {
                if(Event.type == SDL_QUIT)
                {
                    return 0;
                }


                if(Event.type == SDL_KEYDOWN)
                {

                    //movimiento del menu
                    if(Event.key.keysym.sym == SDLK_s)
                    {
                        a++;
                        if(a>4)
                            a=1;
                    }
                    if(Event.key.keysym.sym == SDLK_w)
                    {
                        a--;
                        if(a<1)
                            a=4;
                    }
                    if(Event.key.keysym.sym == SDLK_SPACE)
                    {
                        if(a==1)
                        {
                            cout<<a;
                            juego=2;
                        }

                        //cambiar tamaño de la ventana
                        if(a==3)
                        {
                            screen++;
                            if(screen>3)
                            {
                                screen=1;
                                SDL_SetWindowFullscreen(window,0);
                            }
                            switch(screen)
                            {
                            case 1:
                                SDL_SetWindowSize(window,500,250);
                                break;
                            case 2:
                                SDL_SetWindowSize(window,1000,500);
                                break;
                            case 3:
                                SDL_SetWindowFullscreen(window,1);
                                break;
                            }


                        }
                    }
                }
            }
            //control de las imagenes del menu
            switch(a)
            {
            case 1:
                menu = IMG_LoadTexture(renderer,"menu1.png");
                break;
            case 2:
                menu = IMG_LoadTexture(renderer,"menu2.png");
                break;
            case 3:
                menu = IMG_LoadTexture(renderer,"menu3.png");
                break;
            case 4:
                menu = IMG_LoadTexture(renderer,"menu4.png");
                break;

            }


            SDL_RenderCopy(renderer, menu, NULL, &rect_menu);
            SDL_RenderPresent(renderer);
        }

        //este es el juego
        if(juego==2)
        {
            double diferencia = SDL_GetTicks()-last_frame;
            double ajuste = 17 - diferencia;
            if(ajuste>0)
                SDL_Delay(ajuste);
            last_frame=SDL_GetTicks();


            for(list<Entidad*>::iterator e = entidades.begin();
                    e!=entidades.end();
                    e++)
                (*e)->logica();

            for(list<Entidad*>::iterator e = entidades.begin();
                    e!=entidades.end();
                    e++)
            {
                if((*e)->delete_flag)
                {
                    entidades.remove(*e);
                    break;
                }
            }

            SDL_RenderCopy(renderer, background, NULL, &rect_background);

            for(list<Entidad*>::iterator e = entidades.begin();
                    e!=entidades.end();
                    e++)
                (*e)->dibujar();
            SDL_RenderPresent(renderer);
        }
        // menu de pausa
        if(juego==3)
        {
            //dibuja la pausa
            SDL_RenderCopy(renderer, pausa, NULL, &rect_pausa);
            SDL_RenderPresent(renderer);
            //control de imagenes de pausa
            switch(pause)
            {
            case 0:
                pausa = IMG_LoadTexture(renderer,"pause1.png");
                break;
            case 1:
                pausa = IMG_LoadTexture(renderer,"pause2.png");
                break;
            }
        }
    }
    return 0;
}
