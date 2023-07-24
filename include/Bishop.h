#ifndef PIECE_H_INCLUDED
#include "../include/Piece.h"
#endif

#ifndef BISHOP_H_INCLUDED
#define BISHOP_H_INCLUDED

#include <stdbool.h>

struct Bishop {
    struct Piece base; // The Bishop struct contains a base struct Piece
};

typedef struct Bishop Bishop;

Bishop* createBishop(bool isWhite, int position_X, int position_Y);
void destroyBishop(Bishop* bishop);
bool isBishopMovementPossible(const Bishop* bishop, int destX, int destY);
bool getBishopColor(const Bishop* bishop);
enum PieceName getBishopName(const Bishop* bishop);
int getBishopPositionX(const Bishop* bishop);
int getBishopPositionY(const Bishop* bishop);

#endif
