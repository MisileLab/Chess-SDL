#ifndef PIECE_H_INCLUDED
#include "../include/Piece.h"
#endif

#ifndef PAWN_H_INCLUDED
#define PAWN_H_INCLUDED

#include <stdbool.h>

struct Pawn {
    struct Piece base; // The Pawn struct contains a base struct Piece
    bool hasDiagonalEnemyRight;
    bool hasDiagonalEnemyLeft;
};

typedef struct Pawn Pawn;

Pawn* createPawn(bool isWhite, int position_X, int position_Y);
void destroyPawn(Pawn* pawn);
bool isPawnMovementPossible(const Pawn* pawn, int destX, int destY);
bool getPawnColor(const Pawn* pawn);
enum PieceName getPawnName(const Pawn* pawn);
int getPawnPositionX(const Pawn* pawn);
int getPawnPositionY(const Pawn* pawn);
void setDiagonalEnemy(Pawn* pawn, bool right, bool left);

#endif
