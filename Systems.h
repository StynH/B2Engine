//
// Created by styn2 on 12/1/2019.
//

#ifndef B2BSAND_SYSTEMS_H
#define B2BSAND_SYSTEMS_H

#include "Entity.h"

void velocitySystem(Position* _position, Velocity* _velocity);
void drawSystem(SDL_Renderer* _renderer, const Position* _position, const Rotation* _rotation, const Sprite* _sprite);

#endif //B2BSAND_SYSTEMS_H
