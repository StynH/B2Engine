#include "Systems.h"
#include "DeltaTime.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

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

void collisionSystem(const Position* _position, const Dimension* _dimension, Velocity* _velocity) {
    if (_position->x + (_velocity->vx * timer->deltaTime) + _dimension->width > SCREEN_WIDTH || _position->x + (_velocity->vx * timer->deltaTime) < 0) {
        _velocity->vx = -_velocity->vx;
    }

    if (_position->y + (_velocity->vy * timer->deltaTime) + _dimension->height > SCREEN_HEIGHT || _position->y + (_velocity->vy * timer->deltaTime) < 0) {
        _velocity->vy = -_velocity->vy;
    }
}
