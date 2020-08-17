//
// Created by danielyeste on 30/7/20.
//

#ifndef DEADISNEAR_TEXTUREMANAGER_H
#define DEADISNEAR_TEXTUREMANAGER_H

#include "Game.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName);
    static void Draw(SDL_Texture* tex,SDL_Rect src,
                     SDL_Rect dest,SDL_RendererFlip flip);

};


#endif //DEADISNEAR_TEXTUREMANAGER_H
