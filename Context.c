#include <stdlib.h>
#include "Context.h"
#include "stdio.h"
#include "string.h"

void initContext(Context *_data) {
    EntityData* data = &_data->entityData;

    for(uint32_t i = 0; i < MAX_ENTITIES; ++i){
        data->id[i] = FREE_ID;
    }
}

void addEntity(Context *_data, uint32_t _x, uint32_t _y, uint32_t _width, uint32_t _height, float _angle, Sprite* _sprite) {
    EntityData* data = &_data->entityData;
    const int32_t size = findFirstFreeEntity(_data);

    if(size == NO_FREE_ID_FOUND){
        printf("Failed to add new entity, exceeded limit of %d!", MAX_ENTITIES);
        return;
    }

    data->id[size] = size + 1;

    Position newPosition;
    newPosition.x = _x;
    newPosition.y = _y;
    data->positions[size] = newPosition;

    Dimension dimension;
    dimension.width = _width;
    dimension.height =_height;
    data->dimensions[size] = dimension;

    Rotation rotation;
    rotation.angle = _angle;
    data->rotation[size] = rotation;

    data->sprites[size] = _sprite;
}

void addVelocityComponent(Context* _data, float _vx, float _vy, uint32_t _entityId){
    EntityData* data = &_data->entityData;

    Velocity* component = (Velocity*)malloc(sizeof(Velocity));
    component->vy = _vy;
    component->vx = _vx;

    data->velocity[_entityId] = component;
}

void removeEntity(Context* _data, int16_t _id) {
    EntityData* data = &_data->entityData;
    data->id[_id - 1] = FREE_ID;

    free(data->sprites[_id - 1]);
    data->sprites[_id - 1] = NULL;

    free(data->velocity[_id - 1]);
    data->velocity[_id - 1] = NULL;
}

void showEntityAtPosition(Context *_data, uint16_t _index) {
    printf("Entity #%d, has position %f,%f and dimensions %d, %d\n",
           _index,
           _data->entityData.positions[_index].x,
           _data->entityData.positions[_index].y,
           _data->entityData.dimensions[_index].width,
           _data->entityData.dimensions[_index].height
    );
}

int32_t findFirstFreeEntity(Context *_data) {
    EntityData* data = &_data->entityData;
    for(uint32_t i = 0; i < MAX_ENTITIES; ++i){
        if(data->id[i] == FREE_ID){
            return i;
        }
    }
    return NO_FREE_ID_FOUND;
}
