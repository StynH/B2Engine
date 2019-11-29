#ifndef B2BSAND_ENTITY_H
#define B2BSAND_ENTITY_H

#include <stdint.h>
#include "Graphics.h"

#define MAX_ENTITIES 65536

struct Context;

typedef struct{
    float x;
    float y;
} Position;

typedef struct{
    int32_t width;
    int32_t height;
} Dimension;

typedef struct{
    uint16_t amountOfEntities;
    Position positions[MAX_ENTITIES];
    Dimension dimensions[MAX_ENTITIES];
    Sprite* sprites[MAX_ENTITIES];
} EntityData;

#endif //B2BSAND_ENTITY_H
