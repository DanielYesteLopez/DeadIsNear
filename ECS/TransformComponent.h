//
// Created by danielyeste on 31/7/20.
//

#ifndef DEADISNEAR_TRANSFORMCOMPONENT_H
#define DEADISNEAR_TRANSFORMCOMPONENT_H
#include "Components.h"
#include "../Vector2D.h"
#include "ECS.h"

class TransformComponent: public Component {
public:
    Vector2D position;
    Vector2D velocity;
    int height = 32;
    int width = 32;
    int scale = 1;
    int speed = 1;
    TransformComponent(){
        position.Zero();
    }
    TransformComponent (float x, float y){
        position.x = x;
        position.y= y;
    }
    TransformComponent (float x, float y, int h, int w,int sc) {
        position.x = x;
        position.y = y;
        height = h;
        width = w;
        scale = sc;

    }
    TransformComponent(int sc){
        position.Zero();
        scale = sc;
    }
    void update() override{
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;

    }

    void init() override{
        velocity.Zero();
    }

};
#endif //DEADISNEAR_TRANSFORMCOMPONENT_H
