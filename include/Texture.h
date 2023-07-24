#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <SDL2/SDL.h>

typedef struct Texture {
    // Initializes the variables
    Texture();

    // Deallocates memory
    ~Texture();

    // Loads images from a file
    int loadFromFile(const char* path);

    // Deallocates texture
    void free();

    // Renders texture at some point
    void render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip);

    // Image dimensions
    int getWidth();
    int getHeight();

    // The texture
    SDL_Texture* mTexture;

    // Image dimensions
    int mWidth;
    int mHeight;
} Texture;

#endif
