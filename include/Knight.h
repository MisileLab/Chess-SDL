#ifndef PIECE_H_INCLUDED
#include "../include/Piece.h"
#endif

#ifndef KNIGHT_H_INCLUDED
#define KNIGHT_H_INCLUDED

#include <stdbool.h>

struct Knight {
    struct Piece base; // The Knight struct contains a base struct Piece
};

typedef struct Knight Knight;

Knight* createKnight(bool isWhite, int position_X, int position_Y);
void destroyKnight(Knight* knight);
bool isKnightMovementPossible(const Knight* knight, int destX, int destY);
bool getKnightColor(const Knight* knight);
enum PieceName getKnightName(const Knight* knight);
int getKnightPositionX(const Knight* knight);
int getKnightPositionY(const Knight* knight);

#endif
