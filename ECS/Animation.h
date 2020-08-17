//
// Created by danielyeste on 15/8/20.
//

#ifndef DEADISNEAR_ANIMATION_H
#define DEADISNEAR_ANIMATION_H

struct Animation{
    int index;
    int frames;
    int speed;

    Animation(){

    }
    Animation(int i,int nFrames,int nSpeed){
        index = i;
        frames = nFrames;
        speed = nSpeed;
    }
};

#endif //DEADISNEAR_ANIMATION_H
