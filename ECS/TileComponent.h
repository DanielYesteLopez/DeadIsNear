//
// Created by danielyeste on 5/8/20.
//

#ifndef DEADISNEAR_TILECOMPONENT_H
#define DEADISNEAR_TILECOMPONENT_H
#include "TransformComponent.h"
#include "SDL2/SDL.h"
#include "ECS.h"
#include "Components.h"

class TileComponent : public Component{
public:
    TransformComponent *transform;
    SpritesComponent *sprite;
    TileComponent() = default;
    const char* path;
    SDL_Rect tileRect;
    int tileID;
    TileComponent(int x,int y, int w,int h,int id){
        tileRect.x = x;
        tileRect.y = y;
        tileRect.w = w;
        tileRect.h = h;
        tileID = id;
        switch (tileID) {
            case 0:
                path = "assets/grass.png";
                break;
            case 1:
                path = "assets/dirt.png";
                break;
            case 2:
                path = "assets/water.png";
                break;
            default:
                break;
        }
    }
    void init() override{
        entity->addComponent<TransformComponent>((float)tileRect.x,(float)tileRect.y,
                                                 tileRect.w,tileRect.h,1);
        transform = &entity->getComponent<TransformComponent>();
        entity->addComponent<SpritesComponent>(path);
        sprite = &entity->getComponent<SpritesComponent>();


    }
};
#endif //DEADISNEAR_TILECOMPONENT_H
