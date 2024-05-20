#include "Pawn.h"
//#include "PlayerColor.h"

Pawn::Pawn(PlayerColor c)
{
    playerColor = c;
}

Pawn::~Pawn()
{

}

PlayerColor Pawn::getPlayer()
{
    return playerColor;
}

void Pawn::setPlayer(PlayerColor c)
{
    playerColor = c;
}