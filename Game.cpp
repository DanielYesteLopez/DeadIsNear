//
// Created by danielyeste on 28/7/20.
//
#include <iostream>
#include "Game.h"
#include "ECS/Components.h"
#include "ECS/ECS.h"
#include "TextureManager.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Vector2D.h"
#include "Collision.h"


SDL_Renderer* Game::renderer = nullptr;
Map* map;
Manager manager;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());
SDL_Event Game::event;
std::vector<ColliderComponent*>Game::colliders;
enum groupLabels: std::size_t {
    groupMap,
    groupPlayers,
    groupEnemies,
    groupColliders
};

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
    }
    map = new Map();
    player.addComponent<TransformComponent>(2);
    player.addComponent<SpritesComponent>("assets/hero_animated.png",
                                          true);
    player.addComponent<KeyboardControler>();
    player.addComponent<ColliderComponent>("player");
    Map::LoadMap("assets/map1.txt",16,16);
    player.addGroup(groupPlayers);
    wall.addGroup(groupMap);
    player.addGroup(groupColliders);

}

void Game::update() {
    manager.refresh();
    manager.update();

}
auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));
auto& enemies(manager.getGroup(groupEnemies));
void Game::render() {
    SDL_RenderClear(renderer);
    for(auto& t: tiles){
        t->draw();
    }
    for(auto& p: players){
        p->draw();
    }
    for(auto& e: enemies){
        e->draw();
    }
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
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }

}

void Game::AddTile(int id,int x,int y) {
    auto& tile (manager.addEntity());
    tile.addComponent<TileComponent>(x,y,32,32,id);
    tile.addGroup(groupMap);
}
