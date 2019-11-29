#include "Game.h"
#include "stdio.h"

void updateEntities(Context *_game) {
    EntityData* data = &_game->entityData;

    for(uint16_t i = 0; i < data->amountOfEntities; ++i){
        Position* pos = &data->positions[i];
        pos->y += 0.1f;
        pos->x += 0.1f;
    }
}

void drawEntities(SDL_Renderer* _renderer, Context *_game) {
    const EntityData* data = &_game->entityData;

    for(uint16_t i = 0; i < data->amountOfEntities; ++i){
        Position pos = data->positions[i];
        Sprite* sprite = data->sprites[i];

        SDL_Rect rect;
        rect.x = (int)pos.x;
        rect.y = (int)pos.y;
        rect.w = sprite->width;
        rect.h = sprite->height;

        SDL_RenderCopy(_renderer, sprite->texture, NULL, &rect);
    }
}
