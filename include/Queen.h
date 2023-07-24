#ifndef PIECE_H_INCLUDED
#include "../include/Piece.h"
#endif

#ifndef QUEEN_H_INCLUDED
#define QUEEN_H_INCLUDED

#include <stdbool.h>

struct Queen {
    struct Piece base; // The Queen struct contains a base struct Piece
};

typedef struct Queen Queen;

Queen* createQueen(bool isWhite, int position_X, int position_Y);
void destroyQueen(Queen* queen);
bool isQueenMovementPossible(const Queen* queen, int destX, int destY);
bool getQueenColor(const Queen* queen);
enum PieceName getQueenName(const Queen* queen);
int getQueenPositionX(const Queen* queen);
int getQueenPositionY(const Queen* queen);

#endif
