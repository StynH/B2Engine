#include <SDL_image.h>
#include "Graphics.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

StoredTexture textureLibrary[MAX_TEXTURE];
int16_t amountOfTextures = 0;

void loadSprite(SDL_Renderer* _renderer, Sprite* _sprite, const char* _name) {
    char* buffer = calloc(512, sizeof(char));
    snprintf(buffer, 512, "%s%s", TEXTURE_LOCATION, _name);

    SDL_Texture* texture = seekExistingSprite(buffer);

    bool newTexture = false;
    if(texture == NULL){
        SDL_Surface* tempSurface = IMG_Load(buffer);
        texture = SDL_CreateTextureFromSurface(_renderer, tempSurface);
        SDL_FreeSurface(tempSurface);
        newTexture = true;
    }

    if(_sprite == NULL){
        _sprite = (Sprite*)malloc(sizeof(Sprite));
    }

    _sprite->texture = texture;
    SDL_QueryTexture(texture, NULL, NULL, &_sprite->width, &_sprite->height);

    StoredTexture newStoredTexture;
    newStoredTexture.texture = texture;
    newStoredTexture.name = buffer;

    if(newTexture){
        textureLibrary[amountOfTextures] = newStoredTexture;
        ++amountOfTextures;
    }
}

SDL_Texture* seekExistingSprite(const char *_name) {
    for(uint16_t i = 0; i < amountOfTextures; ++i){
        if(strcmp(textureLibrary[i].name, _name) == 0){
            return textureLibrary[i].texture;
        }
    }
    return NULL;
}

void showSpritesLoaded() {
    printf("Amount of Textures loaded: %d\n", amountOfTextures);
    for(uint16_t i = 0; i < amountOfTextures; ++i){
        printf("[%d]: %s\n", i, textureLibrary[i].name);
    }
}

void destroyTextureLibrary() {
    for(uint16_t i = 0; i < amountOfTextures; ++i){
        SDL_DestroyTexture(textureLibrary[i].texture);
    }
}
