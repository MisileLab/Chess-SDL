#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include "GameState.h"

enum ButtonSprite
{
    BUTTON_SPRITE_PVP = 0,
    BUTTON_SPRITE_CPU = 1,
    BUTTON_SPRITE_EDIT = 2,
    BUTTON_SPRITE_QUIT = 3,
    BUTTON_SPRITE_CONTINUE = 4,
    BUTTON_SPRITE_SAVE = 5,
    BUTTON_SPRITE_LOAD = 6,
    BUTTON_SPRITE_MAIN_MENU = 7,
    BUTTON_SPRITE_TOTAL = 8
}; 

typedef enum ButtonSprite ButtonSprite;

struct Button
{
    // Button constants
    int BUTTON_WIDTH;
    int BUTTON_HEIGHT;
    int TOTAL_BUTTONS;
                                                                                                                       
    // Initializes internal variables
    Button();

    // Sets top left position
    void setPosition(int x, int y);

    void setCurrentSprite(ButtonSprite sprite);

    // Handles mouse event
    void handleEvent(SDL_Event* e, GameState* gm);

    // Shows button sprite
    void render();

    // Top left position
    SDL_Point mPosition;

    // Currently used global sprite
    ButtonSprite mCurrentSprite;
    int check;
};

typedef struct Button Button;

#endif
