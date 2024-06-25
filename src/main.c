#include <stdio.h>
#include <signal.h>
#include <SDL2/SDL.h>
#include "tag.h"
#include "engine/window.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

extern SDL_Window *window;

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
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);;

    SDL_Event e;

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

            SDL_RenderPresent(renderer);
        }
    }
    return 0;
}
