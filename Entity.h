#ifndef B2BSAND_ENTITY_H
#define B2BSAND_ENTITY_H

#include <stdint.h>
#include <stdbool.h>
#include "Graphics.h"

#define MAX_ENTITIES 65536
#define FREE_ID -1
#define NO_FREE_ID_FOUND -1

typedef uint32_t EntityID;

typedef struct{
    float x;
    float y;
} Position;

typedef struct{
    float vx;
    float vy;
} Velocity;

typedef struct{
    int32_t width;
    int32_t height;
} Dimension;

typedef struct {
    float angle;
} Rotation;

typedef enum{
    NO_COLLIDE,
    SOLID
} CollisionType;

typedef struct{
    CollisionType type;
} Collider;

typedef struct{
    bool listens;
} InputListener;

typedef struct{
    int32_t highestId;
    int16_t id[MAX_ENTITIES];
    //Base
    Position positions[MAX_ENTITIES];
    Dimension dimensions[MAX_ENTITIES];
    Rotation rotation[MAX_ENTITIES];
    //Optional components
    Collider collider[MAX_ENTITIES];
    Velocity* velocity[MAX_ENTITIES];
    Sprite* sprites[MAX_ENTITIES];
    //Input
    InputListener inputListeners[MAX_ENTITIES];
} EntityData;

#endif //B2BSAND_ENTITY_H
