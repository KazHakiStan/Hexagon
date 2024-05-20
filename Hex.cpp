#include "Hex.h"
#include "Globals.h"
#include <SFML/Graphics.hpp>
#include <cmath>

Hex::Hex(float x, float y, int di, int dj) {
    color = hexColor;
    isPressed = false;
    pos = {x, y};
    boardPos = {di, dj};
    pawn = nullptr;
    calculateAdjHexesPos(di, dj);
}

Hex::Hex(float x, float y, int di, int dj, Pawn* p) {
    color = hexColor;
    isPressed = false;
    pos = {x, y};
    boardPos = {di, dj};
    pawn = p;
    calculateAdjHexesPos(di, dj);
}

Hex::~Hex()
{

}

void Hex::draw() {
    sf::ConvexShape hexShape;
    hexShape.setPointCount(6);
    hexShape.setFillColor(color);
    hexShape.setOutlineThickness(0.1 * window.getSize().x / hexRadius);
    hexShape.setOutlineColor(sf::Color::Black);

    for (int k = 0; k < 6; ++k) {
        float angle = 2 * M_PI / 6 * k;
        float pointX = getPos().x + hexRadius * std::cos(angle);
        float pointY = getPos().y + hexRadius * std::sin(angle);
        hexShape.setPoint(k, sf::Vector2f(pointX, pointY));
    }
    window.draw(hexShape);

    if (pawn != nullptr) {
        sf::ConvexShape pawnShape;
        pawnShape.setPointCount(6);
        if (pawn->getPlayer() == RED) pawnShape.setFillColor(Player1Color);
        else pawnShape.setFillColor(Player2Color);
        pawnShape.setOutlineThickness(0.1 * window.getSize().x / hexRadius);
        pawnShape.setOutlineColor(sf::Color::Black);

        for (int k = 0; k < 6; ++k) {
            float angle = 2 * M_PI / 6 * k;
            float pointX = pos.x + pawnRadius * std::cos(angle);
            float pointY = pos.y + pawnRadius * std::sin(angle);
            pawnShape.setPoint(k, sf::Vector2f(pointX, pointY));
        }
        window.draw(pawnShape);
    }
}

void Hex::calculateAdjHexesPos(int di, int dj) {
    for (const auto& offset : duplicateOffsets) {
        int diOffset = offset.first;
        int djOffset = offset.second;

        if (
                di + diOffset >= 0
                && di + diOffset < 17
                && dj + djOffset >= 0
                && dj + djOffset < 9
                && boardScheme[di + diOffset][dj + djOffset] == 1)
        {
            adjHexesPos.first.push_back({di + diOffset, dj + djOffset});
        }
    }

    for (const auto& offset : jumpOffsets) {
        int diOffset = offset.first;
        int djOffset = offset.second;

        if (
                di + diOffset >= 0
                && di + diOffset < 17
                && dj + djOffset >= 0
                && dj + djOffset < 9
                && boardScheme[di + diOffset][dj + djOffset] == 1)
        {
            adjHexesPos.second.push_back({di + diOffset, dj + djOffset});
        }
    }
}

std::pair<std::vector<sf::Vector2i>, std::vector<sf::Vector2i>> Hex::getAdjHexesPos() {
    return adjHexesPos;
}

sf::Vector2f Hex::getPos() {
    return pos;
}

sf::Vector2i Hex::getBoardPos() {
    return boardPos;
}

Pawn* Hex::getPawn() {
    return pawn;
}

bool Hex::getState() {
    return isPressed;
}

//float Hex::getHexRadius()
//{
//    return hexRadius;
//}
//
//float Hex::getHexWidth()
//{
//    return hexWidth;
//}
//
//float Hex::getHexHeight()
//{
//    return hexHeight;
//}
//
//float Hex::getPawnRadius()
//{
//    return pawnRadius;
//}
//
//void Hex::setHexRadius(float r)
//{
//    hexRadius = r;
//}
//
//void Hex::setHexWidth(float w)
//{
//    hexWidth = w;
//}
//
//void Hex::setHexHeight(float h)
//{
//    hexHeight = h;
//}
//
//
//void Hex::setPawnRadius(float r)
//{
//    pawnRadius = r;
//}

void Hex::setPawn(Pawn * p) {
    pawn = p;
}

void Hex::setState(bool s)
{
    isPressed = s;
}

void Hex::setColor(sf::Color c) {
    color = c;
}

void Hex::setPos(float x, float y) {
    pos.x = x;
    pos.y = y;
}