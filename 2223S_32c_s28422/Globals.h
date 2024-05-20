#pragma once
#ifndef HEX_GLOBALS_H
#define HEX_GLOBALS_H
#include <SFML/Graphics.hpp>
#include "MenuState.h"
#include "GameState.h"
#include "PlayerColor.h"
#include "Button.h"

extern const std::string saveFolder;
extern std::string selectedSaveGame;
extern sf::Text savedGamesText;
extern sf::Text inputText;
extern sf::Texture bgTexture;
extern sf::Color Player1Color;
extern sf::Color Player2Color;
extern sf::Color hexColor;
extern unsigned int xWindow;
extern unsigned int yWindow;
extern sf::RenderWindow window;
extern float hexRadius;
extern float hexWidth;
extern float hexHeight;
extern float pawnRadius;
extern const int BoardHeight;
extern const int BoardWidth;
extern sf::Font font;
extern sf::Text score1;
extern sf::Text score2;
extern MenuState menuState;
extern GameState gameState;
extern PlayerColor currentPlayer;
extern int boardScheme[17][9];
extern std::array<std::pair<int, int>, 5> results;
extern std::array<std::pair<int, int>, 6> duplicateOffsets;
extern std::array<std::pair<int, int>, 12> jumpOffsets;
#endif //HEX_GLOBALS_H
