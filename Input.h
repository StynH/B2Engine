#ifndef B2BSAND_INPUT_H
#define B2BSAND_INPUT_H

#include <stdint.h>
#include <stdbool.h>
#include <SDL_keycode.h>

typedef struct{
    SDL_Keycode keyReleased;
    SDL_Keycode keyPressed;
} InputHolder;

InputHolder input;
#endif //B2BSAND_INPUT_H
