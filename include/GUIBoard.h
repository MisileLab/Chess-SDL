#ifndef GUIBOARD_H
#define GUIBOARD_H

#include "Piece.h"
#include "States.h"
#include "common.h"

enum PieceName; // You need to define the 'PieceName' enum separately in a C header

struct GUIBoard {
    SDL_Rect board[8][8];
    SDL_Point focus;
    struct Piece* focusedPiece;
};

typedef struct GUIBoard GUIBoard;

void updateFocus(GUIBoard* guiBoard, int x, int y);
int indexToPixel(int index);
void renderPieceOnBoard(GUIBoard* guiBoard, enum PieceName piece, int cor, int ix, int iy);
void renderAllPieces(GUIBoard* guiBoard, States* states);
int checkMovement(GUIBoard* guiBoard, States* states);
void renderPossibleMoves(GUIBoard* guiBoard, States* states);
void renderBestMove(GUIBoard* guiBoard, States* states);
int choosePieceTurn(GUIBoard* guiBoard, GameState* gm, States* states);
void editBoard(GUIBoard* guiBoard, GameState* gm, States* states);

#endif
