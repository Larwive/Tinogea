#ifndef WINDOW_H
#define WINDOW_H
#include <SDL2/SDL.h>
#include <stdio.h>

SDL_Window* window;
SDL_Renderer* renderer;

SDL_Window *init_window();

#endif