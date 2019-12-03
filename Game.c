#include "Game.h"
#include "stdio.h"
#include "Systems.h"

void updateEntities(Context *_game) {
    EntityData* data = &_game->entityData;

    for(uint32_t i = 0; i < data->highestId; ++i){
        if(data->id[i] == FREE_ID) continue;

        inputSystem(data, &data->inputListeners[i], data->velocity[i]);
        collisionSystem(data, &data->collider[i], &data->positions[i], &data->dimensions[i], data->velocity[i]);
        velocitySystem(&data->positions[i], data->velocity[i]);
    }
}

void drawEntities(SDL_Renderer* _renderer, Context *_game) {
    const EntityData* data = &_game->entityData;

    for(uint32_t i = 0; i < data->highestId; ++i){
        if(data->id[i] == FREE_ID || data->sprites[i] == NULL) continue;

        drawSystem(_renderer, &data->positions[i], &data->rotation[i], data->sprites[i]);
    }
}
