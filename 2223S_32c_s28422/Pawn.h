#ifndef HEX_PAWN_H
#define HEX_PAWN_H
#include "PlayerColor.h"

//class Hex;

class Pawn {
private:
    PlayerColor playerColor;
public:
    Pawn(PlayerColor c);
    ~Pawn();

    PlayerColor getPlayer();
    void setPlayer(PlayerColor c);
};


#endif //HEX_PAWN_H
