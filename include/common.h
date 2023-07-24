#ifndef TEXTURE_BUTTON_H
#define TEXTURE_BUTTON_H

#include "Button.h"
#include "Texture.h"
#include <SDL2/SDL.h>

// Mouse button sprites
extern SDL_Rect gSpriteClips[BUTTON_SPRITE_TOTAL];
extern Texture gCheckTexture;
extern Texture gButtonSpriteSheetTexture;

// Buttons objects
extern Button gButtons[];

// The window we'll be rendering to
extern SDL_Window* gWindow;

// The window renderer
extern SDL_Renderer* gRenderer;

// Scene textures
extern Texture gBoard;
extern Texture whitePieces[7];
extern Texture blackPieces[7];
extern Texture gBishop;
extern Texture casaVerde;
extern Texture pieceSelected;
extern Texture bestMove;
extern Texture endGame[3];
extern Texture selection;

#endif
