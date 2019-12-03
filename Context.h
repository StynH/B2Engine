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

EntityID addEntity(Context* _data, int32_t _x, int32_t _y, uint32_t _width, uint32_t _height, float _angle, Sprite* _sprite, CollisionType _collision);
EntityID cloneEntity(Context* _data, EntityID _entityId);

void removeEntity(Context* _data, EntityID _id);
void showEntityAtPosition(Context* _data, EntityID _index);

void setPosition(Context* _data, EntityID _entityId, int32_t _x, int32_t _y);

void addVelocityComponent(Context* _data, float _vx, float _vy, EntityID _entityId);
void addInputListener(Context* _data, bool listens, EntityID _entityId);

int32_t findFirstFreeEntity(Context* _data);

#endif //B2BSAND_CONTEXT_H
