#include "Text.h"
#include "SDL_FontCache.c"

FC_Font* loadFont(SDL_Renderer* _renderer, const char* _fontName, uint8_t _fontSize) {
    char buffer[512];
    snprintf(buffer, sizeof(buffer), "%s%s", FONTS_LOCATIONS, _fontName);

    FC_Font* font = FC_CreateFont();
    FC_LoadFont(font, _renderer, buffer, _fontSize, FC_MakeColor(255,255,255,255), TTF_STYLE_NORMAL);

    return font;
}

void freeFont(FC_Font* _font) {
    FC_FreeFont(_font);
}
