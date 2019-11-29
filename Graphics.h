#ifndef B2BSAND_GRAPHICS_H
#define B2BSAND_GRAPHICS_H

#include <SDL_render.h>

#define TEXTURE_LOCATION "../Assets/Textures/"
#define MAX_TEXTURE 1024

typedef struct{
    SDL_Texture* texture;
    int32_t width;
    int32_t height;
} Sprite;

typedef struct{
    char* name;
    SDL_Texture* texture;
} StoredTexture;

extern StoredTexture textureLibrary[MAX_TEXTURE];
extern int16_t amountOfTextures;

void loadSprite(SDL_Renderer* _renderer, Sprite* _sprite, const char* _name);
SDL_Texture* seekExistingSprite(const char* _name);
void showSpritesLoaded();
void destroyTextureLibrary();

#endif //B2BSAND_GRAPHICS_H
