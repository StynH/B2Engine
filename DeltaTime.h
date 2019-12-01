#ifndef B2BSAND_DELTATIME_H
#define B2BSAND_DELTATIME_H

#include <stdint.h>
#include <SDL_timer.h>
#include <stdio.h>

typedef struct{
    float now;
    float last;
    float deltaTime;
} DeltaTime;

DeltaTime* timer;

void initializeTime();
void tickDeltaTime();
void freeTime();

#endif //B2BSAND_DELTATIME_H
