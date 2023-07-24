#ifndef PIECE_H_INCLUDED
#include "../include/Piece.h"
#endif

#ifndef ROOK_H_INCLUDED
#define ROOK_H_INCLUDED

#include <stdbool.h>

struct Rook {
    struct Piece base; // The Rook struct contains a base struct Piece
};

typedef struct Rook Rook;

Rook* createRook(bool isWhite, int position_X, int position_Y);
void destroyRook(Rook* rook);
bool isRookMovementPossible(const Rook* rook, int destX, int destY);
bool getRookColor(const Rook* rook);
enum PieceName getRookName(const Rook* rook);
int getRookPositionX(const Rook* rook);
int getRookPositionY(const Rook* rook);

#endif
