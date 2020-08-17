//
// Created by danielyeste on 31/7/20.
//

#ifndef DEADISNEAR_SPRITESCOMPONENT_H
#define DEADISNEAR_SPRITESCOMPONENT_H
#include "Components.h"
#include "SDL2/SDL.h"
#include "TransformComponent.h"
#include "../TextureManager.h"
#include "ECS.h"
#include "Animation.h"
#include <map>

class SpritesComponent : public Component{
private:
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect,destRect;
    bool animated = false;
    int frames = 0;
    int speed = 100;
public:
    int animIndex = 0;
    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;
    std::map<const char*,Animation> animation;
    SpritesComponent() = default;
    SpritesComponent(const char* path){
        setTex(path);
    }
    SpritesComponent(const char* path,bool isAnimated){
        animated = isAnimated;

        Animation idle = Animation(0,3,100);
        Animation walk = Animation(1,8,100);
        animation.emplace("Idle",idle);
        animation.emplace("Walk",walk);
        Play("Idle");
        setTex(path);
    }
    ~SpritesComponent(){
        SDL_DestroyTexture(texture);
    }
    void init() override{
        transform = &entity->getComponent<TransformComponent>();
        srcRect.x = srcRect.y = 0;
        srcRect.w = transform->width;
        srcRect.h = transform->height;

    }
    void setTex(const char* path){
        texture = TextureManager::LoadTexture(path);
    }
    void update() override{

        if(animated){
            srcRect.x = srcRect.w*static_cast<int>((SDL_GetTicks()/speed)%frames);
        }
        srcRect.y = animIndex * transform->height;
        destRect.x = static_cast<int>(transform->position.x);
        destRect.y = static_cast<int>(transform->position.y);
        destRect.w = transform->width * transform->scale;
        destRect.h= transform->height * transform->scale;

    }
    void draw() override{
        TextureManager::Draw(texture,srcRect,destRect,spriteFlip);
    }

    void Play(const char* animName){
        frames = animation[animName].frames;
        animIndex = animation[animName].index;
        speed = animation[animName].speed;
    }
};
#endif //DEADISNEAR_SPRITESCOMPONENT_H
