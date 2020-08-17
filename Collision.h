//
// Created by danielyeste on 4/8/20.
//

#ifndef DEADISNEAR_COLLISION_H
#define DEADISNEAR_COLLISION_H
#include "SDL2/SDL.h"
class ColliderComponent;
class Collision {
public:
    static bool AABB(const SDL_Rect& recA,const SDL_Rect& recB);
    static bool AABB(const ColliderComponent colA,const ColliderComponent colB);
};

#endif //DEADISNEAR_COLLISION_H
