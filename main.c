#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <stdio.h>
#include "Context.h"
#include "Game.h"
#include "Graphics.h"
#include "Math.h"
#include "DeltaTime.h"
#include <stdlib.h>
#include <SDL_image.h>
#include <time.h>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

int main( int argc, char* args[] ) {
    srand(time(NULL));

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

            //Show loaded sprites
            showSpritesLoaded();

            //FPS Counter
            int numFrames = 0;
            uint32_t startTime = SDL_GetTicks();

            //Start Delta Time
            initializeTime();

            //Game loop
            while(1){
                ++numFrames;
                Uint32 elapsedMS = SDL_GetTicks() - startTime;

                if (elapsedMS) { // Skip this the first frame
                    double elapsedSeconds = elapsedMS / 1000.0; // Convert to seconds
                    double fps = numFrames / elapsedSeconds; // FPS is Frames / Seconds

                    char buffer[512];
                    sprintf(buffer, "B2 Engine - FPS: %d\n", (int)fps);
                    SDL_SetWindowTitle(window, buffer);
                }

                tickDeltaTime();

                SDL_Event event;
                if (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        // Break out of the loop on quit
                        break;
                    }
                    if(event.type == SDL_KEYDOWN){
                        if(event.key.keysym.sym == SDLK_s){
                            Sprite sprite;
                            loadSprite(renderer, &sprite, "gold.png");
                            EntityID id = addEntity(
                                    game,
                                    randomBetween(0, SCREEN_WIDTH - sprite.height),
                                    randomBetween(0, SCREEN_HEIGHT - sprite.width),
                                    sprite.width, sprite.height,
                                    (float)randomBetween(0, 360),
                                    &sprite,
                                    SOLID
                            );

                            if(id != NO_FREE_ID_FOUND){
                                addVelocityComponent(
                                        game,
                                        (float)randomBetween(-200, 200),
                                        (float)randomBetween(-200, 200),
                                        id
                                );
                            }
                        }
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

    freeTime();
    destroyTextureLibrary();

    //Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}