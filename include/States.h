#ifndef STATES_H
#define STATES_H

#include "Piece.h"
#include "GameState.h"

enum Obstacles { Empty, Friend, Enemy };
enum GameResult { WhiteWins, BlackWins, Draw, NoContest };
enum Level { Easy, Medium, Hard };

struct PiecesValues
{
    int max_Value_X;
    int max_Value_Y;
    int value;
};

struct States
{
    // Vetor que guarda as melhores jogadas de cada peça:
    struct PiecesValues white_values[16];
    struct PiecesValues black_values[16];
    // Vetor de peças do tabuleiro:
    struct Piece* white_pieces[16];
    struct Piece* black_pieces[16];
};

typedef struct States States;

enum Obstacles IsInTheWay(States* states, struct Piece* piece, int x, int y);
enum Obstacles IsInTheSpot(States* states, struct Piece* piece, int x, int y);
int IsCheck(States* states, bool color, int x, int y);
int MovePiece(States* states, struct Piece* piece, int x, int y);
int IsCheckMate(States* states, bool color);
enum GameResult WhoWon(States* states);
int IsPositionValid(States* states, struct Piece* piece, int x, int y);
struct Piece* GetPiece(States* states, int x, int y);
int SetPiece(States* states, struct Piece* piece, int x, int y);
void PlayBestMove(States* states, bool color, enum Level level);
void UpdateBestMoves(States* states);
void SetPieceTurn(States* states, bool color);
bool GetPieceTurn(States* states);
void SaveGame(States* states, enum GameMode mode);
void LoadGame(States* states, enum GameMode mode);
struct PiecesValues GetPieceBestMove(States* states, struct Piece* piece);
void KillAllPieces(States* states);

#endif
