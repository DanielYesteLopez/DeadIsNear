//
// Created by danielyeste on 28/7/20.
//

#include <iostream>
#include "Game.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
SDL_Texture* playerTexture;
SDL_Rect srCr,destR;
Game::Game() {

}

Game::~Game() {

}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if(fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Initialized" << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
        }
        isRunning = true;
    }else{
        isRunning = false;
    }

    SDL_Surface* tmp_surface = IMG_Load("hero.png");
    playerTexture = SDL_CreateTextureFromSurface(renderer,tmp_surface);
    SDL_FreeSurface(tmp_surface);

}

void Game::update() {
    count++;
    destR.h = 32;
    destR.w = 32;

}

void Game::render() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,playerTexture,NULL,NULL);
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Game::running() {
    return isRunning;
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }

}
