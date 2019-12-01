#include "DeltaTime.h"
#include <stdlib.h>

void initializeTime() {
    timer = (DeltaTime*)malloc(sizeof(DeltaTime));
    timer->now = SDL_GetPerformanceCounter();
    timer->deltaTime = 0.f;
}

void tickDeltaTime() {
    timer->last = timer->now;
    timer->now = SDL_GetPerformanceCounter();

    timer->deltaTime = (
            (timer->now - timer->last) * 1000.f /
            (float)SDL_GetPerformanceFrequency()
    ) / 1000.f;
}

void freeTime(){
    free(timer);
}
