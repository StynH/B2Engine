#include "Systems.h"
#include "DeltaTime.h"
#include "Math.h"
#include "Input.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

#define PLAYER_SPEED 250.f

void velocitySystem(Position *_position, const Velocity *_velocity) {
    if(_velocity == NULL) return;

    _position->x += _velocity->vx * timer->deltaTime;
    _position->y += _velocity->vy * timer->deltaTime;
}

void drawSystem(SDL_Renderer* _renderer, const Position* _position, const Rotation* _rotation, const Sprite* _sprite) {
    if(_sprite == NULL) return;

    SDL_Rect rect;
    rect.x = (int)_position->x;
    rect.y = (int)_position->y;
    rect.w = _sprite->width;
    rect.h = _sprite->height;

    SDL_RenderCopyEx(_renderer, _sprite->texture, NULL, &rect, _rotation->angle, NULL, SDL_FLIP_NONE);
}

void collisionSystem(EntityData* _data, const Collider* _collider, const Position* _position, const Dimension* _dimension, Velocity* _velocity) {
    if(_collider->type == NO_COLLIDE || _velocity == NULL) return;

    for(uint32_t i = 0; i < _data->highestId; ++i){
        //Skip if collider is the same.
        if(&_data->collider[i] != _collider && _data->collider[i].type != NO_COLLIDE){

            Position secondPosition = _data->positions[i];
            Dimension secondDimension = _data->dimensions[i];

            Position nextPosition;
            nextPosition.x = _position->x + (_velocity->vx * timer->deltaTime);
            nextPosition.y = _position->y + (_velocity->vy * timer->deltaTime);

            if(intersectRect(&nextPosition, _dimension, &secondPosition, &secondDimension)){
                _velocity->vx = 0;
                _velocity->vy = 0;
                return;
            }
        }
    }
}

void inputSystem(EntityData* _data, const InputListener* _input, Velocity* _velocity){
    if(!_input->listens) return;

    if(input.keyPressed == SDLK_w){
        _velocity->vy = -PLAYER_SPEED;
    }

    if(input.keyPressed == SDLK_d){
        _velocity->vx = PLAYER_SPEED;
    }

    if(input.keyPressed == SDLK_s){
        _velocity->vy = PLAYER_SPEED;
    }

    if(input.keyPressed == SDLK_a){
        _velocity->vx = -PLAYER_SPEED;
    }

    if(input.keyReleased == SDLK_a || input.keyReleased == SDLK_d){
        _velocity->vx = 0;
    }

    if(input.keyReleased == SDLK_w || input.keyReleased == SDLK_s){
        _velocity->vy = 0;
    }
}