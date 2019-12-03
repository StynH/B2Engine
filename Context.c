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

EntityID cloneEntity(Context* _data, EntityID _entityId){
    EntityData* data = &_data->entityData;
    const int32_t size = findFirstFreeEntity(_data);

    data->id[size] = size + 1;
    if(data->id[size] > data->highestId){
        data->highestId = data->id[size];
    }

    Position newPosition;
    newPosition.x = data->positions[_entityId].x;
    newPosition.y = data->positions[_entityId].y;
    data->positions[size] = newPosition;

    Dimension dimension;
    dimension.width = data->dimensions[_entityId].width;
    dimension.height =data->dimensions[_entityId].height;
    data->dimensions[size] = dimension;

    Rotation rotation;
    rotation.angle = data->rotation[_entityId].angle;
    data->rotation[size] = rotation;

    Collider collider;
    collider.type = data->collider[_entityId].type;
    data->collider[size] = collider;

    InputListener input;
    input.listens = data->inputListeners[_entityId].listens;
    data->inputListeners[size] = input;

    data->sprites[size] = data->sprites[_entityId];

    return size;
}

EntityID addEntity(Context* _data, int32_t _x, int32_t _y, uint32_t _width, uint32_t _height, float _angle, Sprite* _sprite, CollisionType _collision) {
    EntityData* data = &_data->entityData;
    const int32_t size = findFirstFreeEntity(_data);

    if(size == NO_FREE_ID_FOUND){
        printf("Failed to add new entity, exceeded limit of %d!", MAX_ENTITIES);
        return NO_FREE_ID_FOUND;
    }

    data->id[size] = size + 1;
    if(data->id[size] > data->highestId){
        data->highestId = data->id[size];
    }

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

    Collider collider;
    collider.type = _collision;
    data->collider[size] = collider;

    InputListener input;
    input.listens = false;
    data->inputListeners[size] = input;

    if(_sprite != NULL){
        data->sprites[size] = _sprite;
    }

    return size;
}

void setPosition(Context* _data, EntityID _entityId, int32_t _x, int32_t _y) {
    EntityData* data = &_data->entityData;

    data->positions[_entityId].x = _x;
    data->positions[_entityId].y = _y;
}

void addVelocityComponent(Context* _data, float _vx, float _vy, EntityID _entityId){
    EntityData* data = &_data->entityData;

    Velocity* component = (Velocity*)malloc(sizeof(Velocity));
    component->vy = _vy;
    component->vx = _vx;

    data->velocity[_entityId] = component;
}

void addInputListener(Context* _data, bool listens, EntityID _entityId){
    EntityData* data = &_data->entityData;

    InputListener listener;
    listener.listens = listens;
    data->inputListeners[_entityId] = listener;
}

void removeEntity(Context* _data, EntityID _id) {
    EntityData* data = &_data->entityData;
    data->id[_id - 1] = FREE_ID;

    free(data->sprites[_id - 1]);
    data->sprites[_id - 1] = NULL;

    free(data->velocity[_id - 1]);
    data->velocity[_id - 1] = NULL;
}

void showEntityAtPosition(Context *_data, EntityID _index) {
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
