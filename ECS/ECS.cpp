//
// Created by danielyeste on 10/8/20.
//

#include "ECS.h"

void Entity::addGroup(Group mGroup) {
    groupBitSet[mGroup] = true;
    manager.AddToGroup(this,mGroup);
}

