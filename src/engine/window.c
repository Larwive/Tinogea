#include "window.h"

extern SDL_Window *window;
extern SDL_Renderer *renderer;

SDL_Window *init_window() {
    printf("Initializing window...\n");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    window = SDL_CreateWindow(
        "Tinogea", 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        640, 480, 
        SDL_WINDOW_SHOWN
    );
    
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    return window;
}