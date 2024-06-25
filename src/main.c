#include <stdio.h>
#include <signal.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "tag.h"
#include "engine/window.h"
#include "../assets/obj/obj.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

SDL_Window *window;
SDL_Renderer *renderer = NULL;

void clean_exit()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
    exit(EXIT_SUCCESS);
}

int main()
{
    signal(SIGINT, clean_exit);
    init_window();

    SDL_DisplayMode dm;
    if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
        fprintf(stderr, "SDL_GetDesktopDisplayMode error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    printf("Screen width: %d\n", dm.w);
    printf("Screen height: %d\n", dm.h);
    unsigned int screen_width = dm.w;
    unsigned int screen_height = dm.h;

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);;

    SDL_Event e;

    SDL_Surface* imageSurface = IMG_Load("assets/obj/obj1/pixil-frame-0.png");
    if (imageSurface == NULL) {
        fprintf(stderr, "IMG_Load error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface); // Free surface, texture holds the data now
    if (texture == NULL) {
        fprintf(stderr, "SDL_CreateTextureFromSurface error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Rect srcRect; // Source rectangle
    

    // Rectangle to define where to render the texture on the screen
    SDL_Rect destRect; // Destination rectangle

    unsigned int frame = 0;    unsigned int state = 0;


    Instance *obj1 = obj1_create(0, 0);


    while (1)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                clean_exit();
            }

            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderClear(renderer);

            
            SDL_Rect fillRect = {WINDOW_WIDTH / 4, WINDOW_HEIGHT / 4, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};
            SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
            SDL_RenderFillRect(renderer, &fillRect);

            srcRect.x = frame*obj1->sprite_data->sprite_width;    // X coordinate of the top left corner
            srcRect.y = state*obj1->sprite_data->sprite_height;    // Y coordinate of the top left corner
            srcRect.w = obj1->sprite_data->sprite_width;  // Width of the rectangle
            srcRect.h = obj1->sprite_data->sprite_height;  // Height of the rectangle

            destRect.x = obj1->x; // Center horizontally
            destRect.y = obj1->y; // Center vertically
            destRect.w = srcRect.w*obj1->scale;
            destRect.h = srcRect.h*obj1->scale++;
            if (obj1->scale > 50) {
                obj1->scale %= 50;
                frame = (++frame)%obj1->sprite_data->max_frames[state];
                if (!frame)
                    state = (++state)%obj1->sprite_data->max_state;
            }

            SDL_RenderCopy(renderer, texture, &srcRect, &destRect);

            SDL_RenderPresent(renderer);
            obj1->x = (++obj1->x)%screen_width;
            obj1->y = (++obj1->y)%screen_height;
        }
    }
    return 0;
}
