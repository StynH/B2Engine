#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <stdio.h>
#include "Context.h"
#include "Game.h"
#include "Graphics.h"
#include <stdlib.h>
#include <SDL_image.h>
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main( int argc, char* args[] ) {
    //Keep track of the frame count
    int frame = 0;

    //The window we'll be rendering to
    SDL_Window* window = NULL;

    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "B2Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Create renderer
            SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

            //Create game context
            Context* game = (Context*)malloc(sizeof(Context));

            //Initialize context
            initContext(game);

            //Create test entities
            for(uint32_t i = 0; i < 1; ++i){
                Sprite sprite;
                loadSprite(renderer, &sprite, "gold.png");
                addEntity(game, 0, 0, sprite.width, sprite.height, &sprite);
                addVelocityComponent(game, 0.02f, 0.02f, i);
            }

            //Show loaded sprites
            showSpritesLoaded();

            //FPS Counter
            int numFrames = 0;
            uint32_t startTime = SDL_GetTicks();

            //Game loop
            while(1){
                ++numFrames;
                Uint32 elapsedMS = SDL_GetTicks() - startTime;

                if (elapsedMS) { // Skip this the first frame
                    double elapsedSeconds = elapsedMS / 1000.0; // Convert to seconds
                    double fps = numFrames / elapsedSeconds; // FPS is Frames / Seconds
                    printf("FPS: %f\n", fps);
                }

                SDL_Event event;
                if (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        // Break out of the loop on quit
                        break;
                    }
                }

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderClear(renderer);

                updateEntities(game);
                drawEntities(renderer, game);

                SDL_RenderPresent(renderer);
            }
        }
    }

    destroyTextureLibrary();

    //Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}