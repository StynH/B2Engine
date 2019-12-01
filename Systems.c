//
// Created by styn2 on 12/1/2019.
//

#include "Systems.h"

void velocitySystem(Position *_position, Velocity *_velocity) {
    _position->x += _velocity->vx;
    _position->y += _velocity->vy;
}
