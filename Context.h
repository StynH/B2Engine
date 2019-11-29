//
// Created by styn2 on 11/29/2019.
//

#ifndef B2BSAND_CONTEXT_H
#define B2BSAND_CONTEXT_H

#include "Entity.h"

typedef struct{
    EntityData entityData;
} Context;

void addEntity(Context* _data, uint32_t _x, uint32_t _y, uint32_t _width, uint32_t _height, Sprite* _sprite);
void showEntityAtPosition(Context* _data, uint16_t _index);

#endif //B2BSAND_CONTEXT_H
