#ifndef HEX_HEX_H
#define HEX_HEX_H
#include <SFML/Graphics.hpp>
#include "Pawn.h"
//#include "Board.h"
//class Board;
//class Pawn;



class Hex {
private:
    sf::Vector2f pos;
    sf::Vector2i boardPos;
    sf::Color color;
    Pawn* pawn;
    bool isPressed;
    std::pair<std::vector<sf::Vector2i>, std::vector<sf::Vector2i>> adjHexesPos;
public:
//    static float hexRadius;
//    static float hexWidth;
//    static float hexHeight;
//    static float pawnRadius;
    Hex(float x, float y, int di, int dj);
    Hex(float x, float y, int di, int dj, Pawn* p);
    ~Hex();

    void draw();
    void calculateAdjHexesPos(int di, int dj);

    std::pair<std::vector<sf::Vector2i>, std::vector<sf::Vector2i>> getAdjHexesPos();
    sf::Vector2f getPos();
    sf::Vector2i getBoardPos();
    Pawn* getPawn();
    bool getState();
//    static float getHexRadius();
//    static float getHexWidth();
//    static float getHexHeight();
//    static float getPawnRadius();

//    static void setHexRadius(float r);
//    static void setHexWidth(float w);
//    static void setHexHeight(float h);
//    static void setPawnRadius(float r);
    void setPawn(Pawn * p);
    void setState(bool s);
    void setColor(sf::Color c);
    void setPos(float x, float y);
};


#endif //HEX_HEX_H
