//
// Created by danielyeste on 28/7/20.
//

#ifndef DEADISNEAR_GAME_H
#define DEADISNEAR_GAME_H
#include <cstdio>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Map.h"
#include <vector>

class ColliderComponent;

class Game {
public:
    Game();
    ~Game();


    void init (const char* title, int xpos, int ypos,int width, int height,bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running();
    static void AddTile(int id,int x, int y);
    static SDL_Renderer *renderer;
    static SDL_Event event;
    static std::vector<ColliderComponent*> colliders;

private:
    int count = 0;
    bool isRunning;
    SDL_Window *window;
};


#endif //DEADISNEAR_GAME_H
