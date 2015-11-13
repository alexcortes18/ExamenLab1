#ifndef PLAYER_H
#define PLAYER_H

#include<SDL.h>
#include<SDL_image.h>
#include<vector>

using namespace std;
class Player
{
   public:
        SDL_Renderer* renderer;
        vector <SDL_Texture*>textures;
        SDL_Rect rect;
        int current_texture;
        int frames;
        Player(SDL_Renderer* renderer);
        virtual ~Player();
        void dibujar();
        void logica();
    protected:
    private:
};

#endif // PLAYER_H
