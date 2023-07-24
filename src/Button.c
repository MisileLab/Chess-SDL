#include "../include/Button.h"
#include "../include/GameState.h"
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "../include/Piece.h"
#include "../include/common.h"
#include "../include/Texture.h"

void Button_construct(Button* button)
{
    button->mPosition.x = 0;
    button->mPosition.y = 0;

    button->mCurrentSprite = BUTTON_SPRITE_MAIN_MENU;
}

void Button_setPosition(Button* button, int x, int y)
{
    button->mPosition.x = x;
    button->mPosition.y = y;
}

void Button_setCurrentSprite(Button* button, ButtonSprite sprite)
{
    button->mCurrentSprite = sprite;
}

void Button_handleEvent(Button* button, SDL_Event* e, GameState* gm)
{
    button->check = 0;

    // If mouse event happened
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN)
    {
        // Get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);

        bool inside = true;

        // Mouse is left of the button
        if (x < button->mPosition.x)
        {
            inside = false;
        }
        // Mouse is right of the button
        else if (x > button->mPosition.x + button->BUTTON_WIDTH)
        {
            inside = false;
        }
        // Mouse above the button
        else if (y < button->mPosition.y)
        {
            inside = false;
        }
        // Mouse below the button
        else if (y > button->mPosition.y + button->BUTTON_HEIGHT)
        {
            inside = false;
        }

        if (inside)
        {
            button->check = 1;
            // Set mouse over sprite
            switch (e->type)
            {
            case SDL_MOUSEMOTION:
                // mCurrentSprite = BUTTON_SPRITE_CONTINUE;
                break;

            case SDL_MOUSEBUTTONDOWN:
                switch (button->mCurrentSprite)
                {
                case BUTTON_SPRITE_PVP:
                    setGameState(gm, GAME_MODE_PVP);
                    break;
                case BUTTON_SPRITE_CPU:
                    setGameState(gm, GAME_MODE_CPU);
                    break;
                case BUTTON_SPRITE_EDIT:
                    setGameState(gm, GAME_MODE_EDIT);
                    break;
                case BUTTON_SPRITE_QUIT:
                    setGameState(gm, GAME_MODE_QUIT);
                    break;
                case BUTTON_SPRITE_CONTINUE:
                    gm->pause = 0;
                    break;
                case BUTTON_SPRITE_SAVE:
                    gm->pause = 0;
                    setGameState(gm, GAME_MODE_SAVE);
                    break;
                case BUTTON_SPRITE_LOAD:
                    gm->pause = 0;
                    setGameState(gm, GAME_MODE_LOAD);
                    break;
                case BUTTON_SPRITE_MAIN_MENU:
                    gm->pause = 0;
                    setGameState(gm, GAME_MODE_MAIN_MENU);
                    break;
                }
                break;
            }
        }
    }
}

void Button_render(Button* button)
{
    // Show current button sprite
    button->render(gButtonSpriteSheetTexture, button->mPosition.x, button->mPosition.y, &(gSpriteClips[(int)button->mCurrentSprite]));

    if (button->check == 1)
    {
        //gCheckTexture.render(mPosition.x,mPosition.y);
        //gBishop.render(mPosition.x + BUTTON_WIDTH/2 - 40 ,mPosition.y);
        enum PieceName kn = KNIGHT;
        button->render(blackPieces[(int)kn], button->mPosition.x + button->BUTTON_WIDTH / 2 - 40, button->mPosition.y);
    }
}
