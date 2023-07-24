#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

int initGraphics();
int loadMedia();
void closeGraphics();

#endif
