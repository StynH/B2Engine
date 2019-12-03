//
// Created by styn2 on 11/29/2019.
//

#ifndef B2BSAND_CONTEXT_H
#define B2BSAND_CONTEXT_H

#include "Entity.h"

typedef struct{
    EntityData entityData;
} Context;

void initContext(Context* _data);

EntityID addEntity(Context* _data, uint32_t _x, uint32_t _y, uint32_t _width, uint32_t _height, float _angle, Sprite* _sprite, CollisionType _collision);

void removeEntity(Context* _data, int16_t _id);
void showEntityAtPosition(Context* _data, uint16_t _index);

void addVelocityComponent(Context* _data, float _vx, float _vy, uint32_t _entityId);
void addInputListener(Context* _data, bool listens, uint32_t _entityId);

int32_t findFirstFreeEntity(Context* _data);

#endif //B2BSAND_CONTEXT_H
