#include <iostream>
#include "Game.h"
Game *game = nullptr;
int main() {

    game = new Game();
    game->init("DeadIsNear",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,false);
    while(game->running()){
        game->update();
        game->handleEvents();
        game->render();
        game->update();
    }
    game->clean();
    return 0;
}
