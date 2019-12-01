//
// Created by styn2 on 12/1/2019.
//

#include "Systems.h"

void velocitySystem(Position *_position, Velocity *_velocity) {
    _position->x += _velocity->vx;
    _position->y += _velocity->vy;
}

void drawSystem(SDL_Renderer* _renderer, const Position* _position, const Rotation* _rotation, const Sprite* _sprite) {
    SDL_Rect rect;
    rect.x = (int)_position->x;
    rect.y = (int)_position->y;
    rect.w = _sprite->width;
    rect.h = _sprite->height;

    SDL_RenderCopyEx(_renderer, _sprite->texture, NULL, &rect, _rotation->angle, NULL, SDL_FLIP_NONE);
}
