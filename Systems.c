#include "Systems.h"
#include "DeltaTime.h"
#include "Math.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

void velocitySystem(Position *_position, const Velocity *_velocity) {
    _position->x += _velocity->vx * timer->deltaTime;
    _position->y += _velocity->vy * timer->deltaTime;
}

void drawSystem(SDL_Renderer* _renderer, const Position* _position, const Rotation* _rotation, const Sprite* _sprite) {
    SDL_Rect rect;
    rect.x = (int)_position->x;
    rect.y = (int)_position->y;
    rect.w = _sprite->width;
    rect.h = _sprite->height;

    SDL_RenderCopyEx(_renderer, _sprite->texture, NULL, &rect, _rotation->angle, NULL, SDL_FLIP_NONE);
}

void collisionSystem(EntityData* _data, const Collider* _collider, const Position* _position, const Dimension* _dimension, Velocity* _velocity) {
    if(_collider->type == NO_COLLIDE) return;

    for(uint32_t i = 0; i < _data->highestId; ++i){
        //Skip if collider is the same.
        if(&_data->collider[i] != _collider && _data->collider[i].type != NO_COLLIDE){

            Position secondPosition = _data->positions[i];
            Dimension secondDimension = _data->dimensions[i];

            if(intersectRect(_position, _dimension, &secondPosition, &secondDimension)){
                _velocity->vx = 0;
                _velocity->vy = 0;
                return;
            }
        }
    }
}
