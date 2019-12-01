#include "Game.h"
#include "stdio.h"
#include "Systems.h"

void updateEntities(Context *_game) {
    EntityData* data = &_game->entityData;

    for(uint32_t i = 0; i < MAX_ENTITIES; ++i){
        if(data->id[i] == FREE_ID) continue;

        if(data->velocity[i] != NULL){
            velocitySystem(&data->positions[i], data->velocity[i]);
        }
    }
}

void drawEntities(SDL_Renderer* _renderer, Context *_game) {
    const EntityData* data = &_game->entityData;

    for(uint32_t i = 0; i < MAX_ENTITIES; ++i){
        if(data->id[i] == FREE_ID) continue;

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
