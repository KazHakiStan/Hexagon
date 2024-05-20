#include "Globals.h"

const std::string saveFolder = "saves/";
std::string selectedSaveGame = "";
sf::Text savedGamesText = sf::Text(font);
sf::Text inputText = sf::Text(font);
sf::Texture bgTexture;
sf::Color Player1Color = sf::Color::Red;
sf::Color Player2Color = sf::Color::Blue;
sf::Color hexColor = sf::Color(184, 223, 236);
unsigned int xWindow = 1000;
unsigned int yWindow = 1000;
sf::RenderWindow window(sf::VideoMode({xWindow, yWindow}), "Hexxagon");
float hexRadius = xWindow / 20;
float hexWidth = 2.0f * hexRadius;
float hexHeight = 1.732f * hexRadius;
float pawnRadius = hexRadius - 0.1 * hexRadius;
const int BoardHeight = 17;
const int BoardWidth = 9;
sf::Font font;
sf::Text score1 = sf::Text(font);
sf::Text score2 = sf::Text(font);
MenuState menuState = MAIN;
GameState gameState = NONE;
PlayerColor currentPlayer = RED;
int boardScheme[BoardHeight][BoardWidth] =
        {{0,0,0,0,1,0,0,0,0},
         {0,0,0,1,0,1,0,0,0},
         {0,0,1,0,1,0,1,0,0},
         {0,1,0,1,0,1,0,1,0},
         {1,0,1,0,1,0,1,0,1},
         {0,1,0,1,0,1,0,1,0},
         {1,0,1,0,0,0,1,0,1},
         {0,1,0,1,0,1,0,1,0},
         {1,0,1,0,1,0,1,0,1},
         {0,1,0,0,0,0,0,1,0},
         {1,0,1,0,1,0,1,0,1},
         {0,1,0,1,0,1,0,1,0},
         {1,0,1,0,1,0,1,0,1},
         {0,1,0,1,0,1,0,1,0},
         {0,0,1,0,1,0,1,0,0},
         {0,0,0,1,0,1,0,0,0},
         {0,0,0,0,1,0,0,0,0}};
std::array<std::pair<int, int>, 5> results =
        {
        std::make_pair(0, 0),
        std::make_pair(0, 0),
        std::make_pair(0, 0),
        std::make_pair(0, 0),
        std::make_pair(0, 0)};
std::array<std::pair<int, int>, 6> duplicateOffsets = {
        std::make_pair(-2, 0),
        std::make_pair(-1, 1),
        std::make_pair(-1, -1),
        std::make_pair(1, 1),
        std::make_pair(1, -1),
        std::make_pair(2, 0)
};

std::array<std::pair<int, int>, 12> jumpOffsets = {
        std::make_pair(-4, 0),
        std::make_pair(-3, 1),
        std::make_pair(-2, 2),
        std::make_pair(0, 2),
        std::make_pair(2, 2),
        std::make_pair(3, 1),
        std::make_pair(4, 0),
        std::make_pair(3, -1),
        std::make_pair(2, -2),
        std::make_pair(0, -2),
        std::make_pair(-2, -2),
        std::make_pair(-3, -1)
};