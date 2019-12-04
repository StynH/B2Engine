#ifndef B2BSAND_TEXT_H
#define B2BSAND_TEXT_H
#include "SDL_FontCache.h"

#define FONTS_LOCATIONS "../Assets/Fonts/"

FC_Font* loadFont(SDL_Renderer* _renderer, const char* _fontName, uint8_t _fontSize);
void freeFont(FC_Font* _font);

#endif //B2BSAND_TEXT_H
