#include "../include/Bishop.h"
#include "../include/Piece.h"
#include <stdlib.h>

/**@brief Método construtor do Bispo
*/

void Bishop_construct(Bishop* bishop, bool isWhite, int position_X, int position_Y)
{
  enum PieceName a = BISHOP;
  bishop->base.name = a;
  bishop->base.isWhite = isWhite;
  bishop->base.position_X = position_X;
  bishop->base.position_Y = position_Y;
  bishop->base.isAlive = true;
  bishop->base.PieceValue = 3;
}

/**@brief Função que valida se o movimento do Bispo é possível
*/

bool Bishop_IsMovementPossible(Bishop* bishop, int FinalPosition_X, int FinalPosition_Y)
{
  if (FinalPosition_X >= 0 && FinalPosition_Y >= 0 && FinalPosition_X < 8 && FinalPosition_Y < 8 && bishop->base.isAlive) //Peça tem que estar no tabuleiro e estar viva
  {
    int movement_x = abs(FinalPosition_X - bishop->base.position_X);
    int movement_y = abs(FinalPosition_Y - bishop->base.position_Y);

    if (movement_x == movement_y && movement_x > 0) //Verificação do movimento na diagonal apenas e posição final diferente da inicial
    {
      return true;
    }
  }

  return false;
}
