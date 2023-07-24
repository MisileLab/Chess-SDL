#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

#include <stdbool.h>

enum PieceName { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };

struct Piece {
    enum PieceName name;
    bool isWhite;
    int position_X;
    int position_Y;
    bool isAlive;
    int PieceValue;
};

typedef struct Piece Piece;

Piece* createPiece();
void destroyPiece(Piece* piece);
int getPieceValue(const Piece* piece);
bool getColor(const Piece* piece);
enum PieceName getName(const Piece* piece);
int getPositionX(const Piece* piece);
int getPositionY(const Piece* piece);
bool isMovementPossible(const Piece* piece, int destX, int destY);
void setDiagonalEnemy(Piece* piece, bool left, bool right);
void setPosition(Piece* piece, int x, int y);
bool getIsAlive(const Piece* piece);
void wakeFromDead(Piece* piece);
void setDead(Piece* piece);

#endif
