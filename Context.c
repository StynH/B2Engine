#include "Context.h"
#include "stdio.h"

void addEntity(Context *_data, uint32_t _x, uint32_t _y, uint32_t _width, uint32_t _height, Sprite* _sprite) {
    EntityData* data = &_data->entityData;
    const uint16_t size = data->amountOfEntities;

    Position newPosition;
    newPosition.x = _x;
    newPosition.y = _y;
    data->positions[size] = newPosition;

    Dimension dimension;
    dimension.width = _width;
    dimension.height =_height;
    data->dimensions[size] = dimension;

    data->sprites[size] = _sprite;

    ++data->amountOfEntities;
}

void showEntityAtPosition(Context *_data, uint16_t _index) {
    if(_index <= _data->entityData.amountOfEntities){
        printf("Entity #%d, has position %d,%d and dimensions %d, %d\n",
                _index,
                _data->entityData.positions[_index].x,
                _data->entityData.positions[_index].y,
                _data->entityData.dimensions[_index].width,
               _data->entityData.dimensions[_index].height
        );
    }
    else{
        printf("Entity index out of bounds! (Index %d)\n", _index);
    }
}
