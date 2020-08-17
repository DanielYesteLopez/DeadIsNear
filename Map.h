//
// Created by danielyeste on 30/7/20.
//

#ifndef DEADISNEAR_MAP_H
#define DEADISNEAR_MAP_H
#include "Game.h"
#include "TextureManager.h"
#include <string>

class Map {
public:
    Map();
    ~Map();
    static void LoadMap(std::string path,int sizeX,int sizeY);
private:
};


#endif //DEADISNEAR_MAP_H
