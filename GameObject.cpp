//
// Created by danielyeste on 30/7/20.
//

#include "GameObject.h"
#include "TextureManager.h"

void GameObject::Update() {
    xpos++;
    ypos++;
    srcRect.h = 64;
    srcRect.w = 64;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w*2;
    destRect.h = srcRect.h * 2;
}

void GameObject::Render() {
    SDL_RenderCopy(Game::renderer,objTexture,&srcRect,&destRect);
}

GameObject::~GameObject() {

}

GameObject::GameObject(const char *textureSheet, int x, int y) {
    objTexture = TextureManager::LoadTexture(textureSheet);
    xpos = x;
    ypos = y;
}
