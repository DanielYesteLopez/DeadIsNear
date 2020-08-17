//
// Created by danielyeste on 1/8/20.
//

#ifndef DEADISNEAR_KEYBOARDCONTROLER_H
#define DEADISNEAR_KEYBOARDCONTROLER_H
#include "../Game.h"
#include "ECS.h"
#include "Components.h"
#include <queue>
static int mouseX,mouseY;
class KeyboardControler:public Component {
public:
    std::queue<int> mouseBresenhaim;
    TransformComponent *transform;
    SpritesComponent *sprite;
    void init() override{
        transform = &entity->getComponent<TransformComponent>();
        sprite = &entity->getComponent<SpritesComponent>();
    }
    void update() override{
        /*if(Game::event.type == SDL_KEYDOWN){
            switch(Game::event.key.keysym.sym){
                case SDLK_w:
                    transform->velocity.y = -1;
                    sprite->Play("Walk");
                    break;
                case SDLK_s:
                    transform->velocity.y = 1;
                    sprite->Play("Walk");
                    break;
                case SDLK_a:
                    transform->velocity.x = -1;
                    sprite->Play("Walk");
                    sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
                    break;
                case SDLK_d:
                    transform->velocity.x = +1;
                    sprite->Play("Walk");
                    break;
                default:
                    break;

            }
        }
        if(Game::event.type == SDL_KEYUP){
            switch(Game::event.key.keysym.sym){
                case SDLK_w:
                    transform->velocity.y = 0;
                    sprite->Play("Idle");
                    break;
                case SDLK_s:
                    transform->velocity.y = 0;
                    sprite->Play("Idle");
                    break;
                case SDLK_a:
                    transform->velocity.x = 0;
                    sprite->Play("Idle");
                    sprite->spriteFlip = SDL_FLIP_NONE;
                    break;
                case SDLK_d:
                    transform->velocity.x = 0;
                    sprite->Play("Idle");
                    break;
                default:
                    break;

            }

        }*/
        if(Game::event.type == SDL_MOUSEBUTTONDOWN) {
            SDL_GetMouseState(&mouseX, &mouseY);
            mouseX -= 32;
            mouseY -= 32;
            clear(mouseBresenhaim);
            bresenham(        transform->position.x,
                              transform->position.y,
                              mouseX,
                              mouseY
            );
        }else if(!mouseBresenhaim.empty()){
            std::cout<<mouseBresenhaim.front() - transform->position.x<< "\n";
            if((mouseBresenhaim.front() - transform->position.x) >= 0){
                sprite->spriteFlip = SDL_FLIP_NONE;
                sprite->Play("Walk");
            }else{
                sprite->Play("Walk");
                sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
            }
            transform->position.x = mouseBresenhaim.front();
            mouseBresenhaim.pop();
            transform->position.y = mouseBresenhaim.front();
            mouseBresenhaim.pop();
            if (mouseBresenhaim.empty()){
                sprite->Play("Idle");
            }
        }

    }


    void bresenham(int x1, int y1, int x2, int y2){
        int dx,dy,incYi,incXi,incYr,incXr,avr,av,avi,x,y,temp;
        dx=x2-x1;
        dy=y2-y1;
        if(dy >= 0){
            incYi = 1;
        }else{
            dy = dy*-1;
            incYi = -1;
        }

        if(dx >= 0){
            incXi = 1;
        }else{
            dx = dx*-1;
            incXi = -1;
        }
        if(dx >= dy){
            incYr = 0;
            incXr = incXi;
        }else{
            incXr = 0;
           incYr = incYi;
           temp = dx;
           dx = dy;
           dy = temp;
        }
        x = x1;
        y = y1;
        avr = 2*dy;
        av = avr -dx;
        avi = av-dx;

        while(x != x2){
            mouseBresenhaim.push(x);
            mouseBresenhaim.push(y);
            if(av >= 0){
                x = x+incXi;
                y = y+ incYi;
                av = av+avi;
            }else{
                x = x+incXr;
                y = y+incYr;
                av = av+avr;
            }
        }



    }
    void clear( std::queue<int> &q )
    {
        std::queue<int> empty;
        std::swap( q, empty );
    }

};


#endif //DEADISNEAR_KEYBOARDCONTROLER_H
