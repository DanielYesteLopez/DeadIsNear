//
// Created by danielyeste on 30/7/20.
//

#include "TextureManager.h"

SDL_Texture *TextureManager::LoadTexture(const char *fileName) {
    SDL_Surface* tempsurface = IMG_Load(fileName);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer,tempsurface);
    SDL_FreeSurface(tempsurface);
    return texture;

}

void TextureManager::Draw(SDL_Texture *tex, SDL_Rect src,
                          SDL_Rect dest,SDL_RendererFlip flip) {
    SDL_RenderCopyEx(Game::renderer,tex, &src, &dest,NULL,NULL,flip);
}
