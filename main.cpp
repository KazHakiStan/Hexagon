#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include "Globals.h"
#include "Hex.h"
#include "PlayerColor.h"
#include "Board.h"

//class Hex {
//public:
//    using hexRadius = xWindow / 20;
//    using hexWidth =
//};

//unsigned int xWindow = 1080;
//unsigned int yWindow = 1024;
//sf::RenderWindow window(sf::VideoMode({xWindow, yWindow}), "Hexxagon");
//const sf::Color Player1Color = sf::Color::Red;
//const sf::Color Player2Color = sf::Color::Blue;
//sf::Color hexColor = sf::Color(184, 223, 236);
//const int BoardHeight = 17;
//const int BoardWidth = 9;
//sf::Font font;
//sf::Text score1 = sf::Text(font);
//sf::Text score2 = sf::Text(font);
//float hexRadius = xWindow / 20;
//float hexWidth = 2.0f * hexRadius;
//float hexHeight = 1.732f * hexRadius;
//float pawnRadius = hexRadius - 0.1 * hexRadius;
//int boardScheme[BoardHeight][BoardWidth] =
//        {{0,0,0,0,1,0,0,0,0},
//         {0,0,0,1,0,1,0,0,0},
//         {0,0,1,0,1,0,1,0,0},
//         {0,1,0,1,0,1,0,1,0},
//         {1,0,1,0,1,0,1,0,1},
//         {0,1,0,1,0,1,0,1,0},
//         {1,0,1,0,0,0,1,0,1},
//         {0,1,0,1,0,1,0,1,0},
//         {1,0,1,0,1,0,1,0,1},
//         {0,1,0,0,0,0,0,1,0},
//         {1,0,1,0,1,0,1,0,1},
//         {0,1,0,1,0,1,0,1,0},
//         {1,0,1,0,1,0,1,0,1},
//         {0,1,0,1,0,1,0,1,0},
//         {0,0,1,0,1,0,1,0,0},
//         {0,0,0,1,0,1,0,0,0},
//         {0,0,0,0,1,0,0,0,0}};
//std::array<std::pair<int, int>, 6> duplicateOffsets = {
//        std::make_pair(-2, 0),
//        std::make_pair(-1, 1),
//        std::make_pair(-1, -1),
//        std::make_pair(1, 1),
//        std::make_pair(1, -1),
//        std::make_pair(2, 0)
//};
//
//std::array<std::pair<int, int>, 12> jumpOffsets = {
//        std::make_pair(-4, 0),
//        std::make_pair(-3, 1),
//        std::make_pair(-2, 2),
//        std::make_pair(0, 2),
//        std::make_pair(2, 2),
//        std::make_pair(3, 1),
//        std::make_pair(4, 0),
//        std::make_pair(3, -1),
//        std::make_pair(2, -2),
//        std::make_pair(0, -2),
//        std::make_pair(-2, -2),
//        std::make_pair(-3, -1)
//};

//enum PlayerColor {
//    RED,
//    BLUE
//};

//class Pawn {
//private:
//    PlayerColor playerColor;
//public:
//    Pawn(PlayerColor c) {
//        playerColor = c;
//    }
//
//    PlayerColor getPlayer() {
//        return playerColor;
//    }
//
//    void setPlayer(PlayerColor c) {
//        playerColor = c;
//    }
//};

//class Hex {
//private:
//    sf::Vector2f pos;
//    sf::Vector2i boardPos;
//    sf::Color color;
//    Pawn* pawn;
//    bool isPressed;
//    std::pair<std::vector<sf::Vector2i>, std::vector<sf::Vector2i>> adjHexesPos;
//public:
//    Hex(float x, float y, int di, int dj) {
//        color = hexColor;
//        isPressed = false;
//        pos = {x, y};
//        boardPos = {di, dj};
//        pawn = nullptr;
//        calculateAdjHexesPos(di, dj);
//    }
//
//    Hex(float x, float y, int di, int dj, Pawn* p) {
//        color = hexColor;
//        isPressed = false;
//        pos = {x, y};
//        boardPos = {di, dj};
//        pawn = p;
//        calculateAdjHexesPos(di, dj);
//    }
//
//    void draw() {
//        sf::ConvexShape hexShape;
//        hexShape.setPointCount(6);
//        hexShape.setFillColor(color);
//        hexShape.setOutlineThickness(0.1 * window.getSize().x / hexRadius);
//        hexShape.setOutlineColor(sf::Color::Black);
//
//        for (int k = 0; k < 6; ++k) {
//            float angle = 2 * M_PI / 6 * k;
//            float pointX = getPos().x + hexRadius * std::cos(angle);
//            float pointY = getPos().y + hexRadius * std::sin(angle);
//            hexShape.setPoint(k, sf::Vector2f(pointX, pointY));
//        }
//        window.draw(hexShape);
//
//        if (pawn != nullptr) {
//            sf::ConvexShape pawnShape;
//            pawnShape.setPointCount(6);
//            if (pawn->getPlayer() == RED) pawnShape.setFillColor(Player1Color);
//            else pawnShape.setFillColor(Player2Color);
//            pawnShape.setOutlineThickness(0.1 * window.getSize().x / hexRadius);
//            pawnShape.setOutlineColor(sf::Color::Black);
//
//            for (int k = 0; k < 6; ++k) {
//                float angle = 2 * M_PI / 6 * k;
//                float pointX = pos.x + pawnRadius * std::cos(angle);
//                float pointY = pos.y + pawnRadius * std::sin(angle);
//                pawnShape.setPoint(k, sf::Vector2f(pointX, pointY));
//            }
//            window.draw(pawnShape);
//        }
//    }
//
//    void calculateAdjHexesPos(int di, int dj) {
//        for (const auto& offset : duplicateOffsets) {
//            int diOffset = offset.first;
//            int djOffset = offset.second;
//
//            if (
//                    di + diOffset >= 0
//                    && di + diOffset < 17
//                    && dj + djOffset >= 0
//                    && dj + djOffset < 9
//                    && boardScheme[di + diOffset][dj + djOffset] == 1)
//            {
//                adjHexesPos.first.push_back({di + diOffset, dj + djOffset});
//            }
//        }
//
//        for (const auto& offset : jumpOffsets) {
//            int diOffset = offset.first;
//            int djOffset = offset.second;
//
//            if (
//                    di + diOffset >= 0
//                    && di + diOffset < 17
//                    && dj + djOffset >= 0
//                    && dj + djOffset < 9
//                    && boardScheme[di + diOffset][dj + djOffset] == 1)
//            {
//                adjHexesPos.second.push_back({di + diOffset, dj + djOffset});
//            }
//        }
//    }
//
//    std::pair<std::vector<sf::Vector2i>, std::vector<sf::Vector2i>> getAdjHexesPos() {
//        return adjHexesPos;
//    }
//
//    sf::Vector2f getPos() {
//        return pos;
//    }
//
//    sf::Vector2i getBoardPos() {
//        return boardPos;
//    }
//
//    Pawn* getPawn() {
//        return pawn;
//    }
//
//    bool getState() {
//        return isPressed;
//    }
//
//    void setPawn(Pawn * p) {
//        pawn = p;
//    }
//
//    void setState(bool s)
//    {
//        isPressed = s;
//    }
//
//    void setColor(sf::Color c) {
//        color = c;
//    }
//
//    void setPos(float x, float y) {
//        pos.x = x;
//        pos.y = y;
//    }
//};

//class Board {
//private:
//    float bx = window.getSize().x / 2;
//    float by = hexRadius * 3;
//    std::vector<Hex*> board = {};
//    sf::Vector2i score = {3, 3};
//    PlayerColor currentPlayer = RED;
//    Hex* currentHex = nullptr;
//    bool vsComp = false;
//public:
//    Board() {
//        for (int i = 0; i < BoardHeight; i++) {
//            float temp = bx;
//            for (int j = 0; j < BoardWidth; j++) {
//                if (boardScheme[i][j] == 1) {
//                    if (
//                            (i == 0 && j == 4) ||
//                            (i == 12 && j == 0) ||
//                            (i == 12 && j == 8))
//                    {
//                        board.push_back(new Hex(temp, by, i, j, new Pawn(BLUE)));
//                    }
//                    else if (
//                            (i == 4 && j == 0) ||
//                            (i == 4 && j == 8) ||
//                            (i == 16 && j == 4))
//                    {
//                        board.push_back(new Hex(temp, by, i, j, new Pawn(RED)));
//                    }
//                    else board.push_back(new Hex(temp, by, i, j));
//                    temp += 3 * hexWidth / 2;
//                }
//                else if ((i == 6 && j == 4) || (i == 9 && j == 3) || (i == 9 && j == 5)) {
//                    temp += 3 * hexWidth / 2;
//                }
//            }
//            by += hexHeight / 2;
//            if (i < 4 || (i < 12 && i % 2 != 0)) {
//                bx -= 3 * hexWidth / 4;
//                continue;
//            }
//            else {
//                bx += 3 * hexWidth / 4;
//                continue;
//            }
//        }
//    }
//
//    void resizeBoard() {
//        float rbx = window.getSize().x / 2;
//        float rby = hexRadius * 3;
//        std::vector<Hex*>::iterator it = board.begin();
//        for (int i = 0; i < BoardHeight; i++) {
//            float temp = rbx;
//            for (int j = 0; j < BoardWidth; j++) {
//                if (boardScheme[i][j] == 1) {
//                    (*it++)->setPos(temp, rby);
//                    temp += 3 * hexWidth / 2;
//                } else if ((i == 6 && j == 4) || (i == 9 && j == 3) || (i == 9 && j == 5))
//                {
//                    temp += 3 * hexWidth / 2;
//                }
//            }
//            rby += hexHeight / 2;
//            if (i < 4 || (i < 12 && i % 2 != 0)) {
//                rbx -= 3 * hexWidth / 4;
//                continue;
//            }
//            else {
//                rbx += 3 * hexWidth / 4;
//                continue;
//            }
//        }
//    }
//
//    void handleInput() {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//            else if (event.type == sf::Event::MouseButtonPressed) {
//                auto mx = sf::Mouse::getPosition(window).x;
//                auto my = sf::Mouse::getPosition(window).y;
//                if (event.mouseButton.button == sf::Mouse::Left)
//                {
//                    Hex* clickedHex = nullptr;
//                    for (Hex* hex : board) {
//                        if (isClickableArea(mx, my, hexHeight / 2, hex->getPos().x, hex->getPos().y))
//                        {
//                            clickedHex = hex;
//                            break;
//                        }
//                    }
//                    if (clickedHex == nullptr) return;
//                    if (currentHex == nullptr)
//                    {
//                        if (
//                                clickedHex->getPawn() != nullptr
//                                && clickedHex->getPawn()->getPlayer() == currentPlayer)
//                        {
//                            clickedHex->setState(true);
//                            currentHex = clickedHex;
//                            highlightHexes(clickedHex);
//                        }
//                    } else
//                    {
//                        if (clickedHex == currentHex)
//                        {
//                            clickedHex->setState(false);
//                            currentHex = nullptr;
//                            highlightHexes(clickedHex);
//                        } else
//                        {
//                            makeMove(currentHex, clickedHex);
//                        }
//                    }
//                    clickedHex = nullptr;
//                }
//            }
//            else if (event.type == sf::Event::Resized)
//            {
//                sf::FloatRect visibleArea({0, 0}, sf::Vector2f(event.size.width, event.size.height));
//                if (window.getSize().x > 1080) window.setSize({1080, 1080});
//                auto newSize = std::max({window.getSize().y, window.getSize().y});
//                window.setSize({newSize, newSize});
//                window.setView(sf::View(visibleArea));
//                hexRadius = (window.getSize().x <= window.getSize().y) ? (window.getSize().x - 30) / 14 : (window.getSize().y - 30) / 14;
//                hexRadius = window.getSize().x / 20;
//                hexWidth = 2.0f * hexRadius;
//                hexHeight = 1.732f * hexRadius;
//                pawnRadius = hexRadius - 0.1 * hexRadius;
//                resizeBoard();
//            }
//        }
//    }
//
//    std::pair<std::vector<Hex*>, std::vector<Hex*>> getMoves(Hex* hex)
//    {
//        std::pair<std::vector<Hex*>, std::vector<Hex*>> moves;
//        for (sf::Vector2i hexPos : hex->getAdjHexesPos().first)
//        {
//            for (Hex* h : board)
//            {
//                if (h->getBoardPos() == hexPos && h->getPawn() == nullptr)
//                {
//                    moves.first.push_back(h);
////                    std::cout << "added move " << h << " for " << hex << std::endl;
//                }
//            }
//        }
//        for (sf::Vector2i hexPos : hex->getAdjHexesPos().second)
//        {
//            for (Hex* h : board)
//            {
//                if (h->getBoardPos() == hexPos && h->getPawn() == nullptr) {
//                    moves.second.push_back(h);
////                    std::cout << "added jump " << &h << " for " << hex << std::endl;
//                }
//            }
//        }
//        return moves;
//    }
//
//    bool isGameOver() {
//        if (score.x + score.y == board.size() || !possibleMoves(RED) || !possibleMoves(BLUE) || score.x == 0 || score.y == 0) return true;
//        return false;
//    }
//
//    std::vector<Hex*> getAdjHexesWithPawns(Hex* hex) {
//        std::vector<Hex*> adjHexesWithPawns;
//        for (sf::Vector2i hexPos : hex->getAdjHexesPos().first) {
//            for (Hex* h : board) {
//                if (h->getBoardPos() == hexPos && h->getPawn() != nullptr)
//                    adjHexesWithPawns.push_back(h);
//            }
//        }
//        return adjHexesWithPawns;
//    }
//
//    bool possibleMoves(PlayerColor player) {
//        for (Hex* h : board) {
//            if (
//                    h->getPawn() != nullptr
//                    && h->getPawn()->getPlayer() == player
//                    && (getMoves(h).first.size() != 0 || getMoves(h).second.size() != 0))
//                return true;
//        }
//        return false;
//    }
//
//    bool isValidMove(Hex* h1, Hex* h2)
//    {
//        std::pair<std::vector<Hex*>, std::vector<Hex*>> moves = getMoves(h1);
//        if (moves.first.empty()) {
//            std::cout<<"GOVNO " << h1 << std::endl;
//        }
//        for (Hex* hex : moves.first)
//        {
//            if (hex == h2)
//            {
//                return true;
//            }
//        }
//        return false;
//    }
//
//    bool isValidJump(Hex* h1, Hex* h2)
//    {
//        for (Hex* hex : getMoves(h1).second)
//        {
//            if (hex == h2)
//            {
//                return true;
//            }
//        }
//        return false;
//    }
//
//    void makeMove(Hex* h1, Hex* h2)
//    {
//        if (isValidMove(h1, h2))
//        {
//            h2->setPawn(new Pawn(currentPlayer));
//            if (currentPlayer == RED) score.x++;
//            else score.y++;
//            for (Hex* h : getAdjHexesWithPawns(h2))
//                if (h->getPawn()->getPlayer() != currentPlayer)
//                {
//                    h->getPawn()->setPlayer(currentPlayer);
//                    if (currentPlayer == RED)
//                    {
//                        score.x++;
//                        score.y--;
//                    } else {
//                        score.x--;
//                        score.y++;
//                    }
//                }
//        }
//        else if (isValidJump(h1, h2))
//        {
//            h2->setPawn(h1->getPawn());
//            h1->setPawn(nullptr);
//            for (Hex* h : getAdjHexesWithPawns(h2))
//                if (h->getPawn()->getPlayer() != currentPlayer)
//                {
//                    h->getPawn()->setPlayer(currentPlayer);
//                    if (currentPlayer == RED)
//                    {
//                        score.x++;
//                        score.y--;
//                    } else {
//                        score.x--;
//                        score.y++;
//                    }
//                }
//        }
//        else
//        {
//            h1->setState(false);
//            h2->setState(false);
//            currentHex = nullptr;
//            highlightHexes(h1);
//            return;
//        }
//
//        h1->setState(false);
//        h2->setState(false);
//        currentPlayer = (currentPlayer == RED) ? BLUE : RED;
//        std::cout<<"Made move"<<std::endl;
//        currentHex = nullptr;
//        highlightHexes(h1);
//        if (vsComp && currentPlayer == BLUE) {
//            std::cout<< "Control step 1" << std::endl;
//            std::pair<Hex*, Hex*> move = compMove();
//            std::cout<< "Control step 2" << std::endl;
//            std::cout<< "best move : " << move.first << " to " << move.second << std::endl;
//            makeMove(move.first, move.second);
//            std::cout<< "Computer made move" << std::endl;
//        }
//    }
//
//    int countTargetPawns(Hex* hex)
//    {
//        int count = 0;
//        for (Hex* h : getAdjHexesWithPawns(hex))
//        {
//            if (h->getPawn()->getPlayer() == RED) count++;
//        }
//        return count;
//    }
//
//    std::pair<Hex*, Hex*> compMove()
//    {
//        int maxTargetPawns = 0;
//        int hexTargetPawns;
//        std::pair<Hex*, Hex*> bestMove;
//
//        for (Hex* h : board)
//        {
//            if (h->getPawn() != nullptr && h->getPawn()->getPlayer() == BLUE)
//            {
//                for (Hex* hex : getMoves(h).second)
//                {
//                    hexTargetPawns = countTargetPawns(hex);
//                    if (hexTargetPawns >= maxTargetPawns && isValidJump(h, hex))
//                    {
//                        maxTargetPawns = hexTargetPawns;
//                        bestMove.first = h;
//                        bestMove.second = hex;
//                    }
//                }
//                for (Hex* hex : getMoves(h).first)
//                {
//                    hexTargetPawns = countTargetPawns(hex) + 1;
//                    if (hexTargetPawns >= maxTargetPawns && isValidMove(h, hex))
//                    {
//                        maxTargetPawns = hexTargetPawns;
//                        bestMove.first = h;
//                        bestMove.second = hex;
//                    }
//                }
//            }
//        }
//        return bestMove;
//    }
//
//    void highlightHexes(Hex* hex)
//    {
//        std::pair<std::vector<Hex*>, std::vector<Hex*>> moves;
//        for (sf::Vector2i hexPos : hex->getAdjHexesPos().first){
//            for (Hex* h : board) {
//                if (h->getBoardPos() == hexPos) moves.first.push_back(h);
//            }
//        }
//        for (sf::Vector2i hexPos : hex->getAdjHexesPos().second){
//            for (Hex* h : board) {
//                if (h->getBoardPos() == hexPos) moves.second.push_back(h);
//            }
//        }
//        if (!moves.first.empty())
//        {
//            for (Hex* h : moves.first)
//            {
//                if (currentHex != nullptr && h->getPawn() == nullptr)
//                {
//                    h->setColor(sf::Color::Green);
//                }
//                if (currentHex == nullptr)
//                {
//                    hex->setColor(hexColor);
//                    h->setColor(hexColor);
//                }
//            }
//        }
//        if (!moves.second.empty())
//        {
//            for (Hex* h : moves.second)
//            {
//                if (currentHex != nullptr && h->getPawn() == nullptr)
//                {
//                    hex->setColor(sf::Color::Yellow);
//                    h->setColor(sf::Color::Yellow);
//                }
//
//                if (currentHex == nullptr)
//                {
//                    hex->setColor(hexColor);
//                    h->setColor(hexColor);
//                }
//            }
//        }
//    }
//
//    bool isClickableArea(int cx, int cy, int r, int x, int y)
//    {
//        int dist = (x - cx) * (x - cx) + (y - cy) * (y - cy);
//        if ( dist <= r * r)
//            return true;
//        else
//            return false;
//    }
//
//    void drawScore() {
//        sf::ConvexShape scoreShape;
//        scoreShape.setOutlineThickness(2.0f);
//        scoreShape.setOutlineColor(sf::Color::Black);
//        scoreShape.setPointCount(4);
//        scoreShape.setFillColor(sf::Color::Red);
//        scoreShape.setPoint(0, sf::Vector2f(0, window.getSize().y / hexRadius));
//        scoreShape.setPoint(1, sf::Vector2f(0, 2 * window.getSize().y / hexRadius));
//        scoreShape.setPoint(2, sf::Vector2f(window.getSize().x / 10, 2 * window.getSize().y / hexRadius));
//        scoreShape.setPoint(3, sf::Vector2f(window.getSize().x / 10, window.getSize().y / hexRadius));
//        window.draw(scoreShape);
//        scoreShape.setFillColor(sf::Color::Blue);
//        scoreShape.setPoint(0, sf::Vector2f(0, window.getSize().y / hexRadius + hexRadius));
//        scoreShape.setPoint(1, sf::Vector2f(0, 2 * window.getSize().y / hexRadius + hexRadius));
//        scoreShape.setPoint(2, sf::Vector2f(window.getSize().x / 10, 2 * window.getSize().y / hexRadius + hexRadius));
//        scoreShape.setPoint(3, sf::Vector2f(window.getSize().x / 10, window.getSize().y / hexRadius + hexRadius));
//        window.draw(scoreShape);
//        score1.setCharacterSize(hexRadius);
//        score1.setFillColor(sf::Color::White);
//        score1.setOutlineThickness(1.0f);
//        score1.setOutlineColor(sf::Color::Red);
//        score1.setPosition(sf::Vector2f(window.getSize().x / 10, window.getSize().y / hexRadius / 2));
//        score1.setString(std::to_string(score.x));
//        score2.setCharacterSize(hexRadius);
//        score2.setFillColor(sf::Color::White);
//        score2.setOutlineThickness(1.0f);
//        score2.setOutlineColor(sf::Color::Blue);
//        score2.setPosition(sf::Vector2f(window.getSize().x / 10, window.getSize().y / hexRadius / 2 + hexRadius));
//        score2.setString(std::to_string(score.y));
//        window.draw(score1);
//        window.draw(score2);
//    }
//
//    void render() {
//        window.clear(sf::Color::Black);
//
//        for (Hex* h : board) {
//            h->draw();
//        }
//
//        drawScore();
//
//        menu.draw(window);
//
//        window.display();
//    }
//
//    PlayerColor getCurrentPlayer() {
//        return currentPlayer;
//    }
//
//    sf::Vector2i getScore() {
//        return score;
//    }
//
//    void setOpponent(bool b)
//    {
//        vsComp = b;
//    }
//};

int main()
{
    if (!std::filesystem::exists(saveFolder))
    {
        if (!std::filesystem::create_directory(saveFolder))
        {
            std::cout << "Failed to create save directory." << std::endl;
            return -1;
        }
    }
    if (!font.loadFromFile("D:\\Projects\\cpp\\hex\\arial.ttf")) {
        std::cout << "Failed to load fonts" << std::endl;
    }
    if (!bgTexture.loadFromFile("D:\\Projects\\cpp\\hex\\pja.png")) {
        std::cout << "Failed to load background" << std::endl;
    }
    window.setFramerateLimit(60);
    Board board = *new Board();
    board.loadResults();
    while (window.isOpen()) {
        board.handleInput();
        board.render();
        if (board.isGameOver() && gameState == GOING) {
            std::cout << "Game Over!" << std::endl;
            std::cout << "Player 1 Pawns: " << board.getScore().x << std::endl;
            std::cout << "Player 2 Pawns: " << board.getScore().y << std::endl;
            if (board.getScore().x > board.getScore().y)
                std::cout << "Player 1 Wins!" << std::endl;
            else if (board.getScore().x < board.getScore().y)
                std::cout << "Player 2 Wins!" << std::endl;
            else
                std::cout << "It's a Draw!" << std::endl;
            menuState = MAIN;
            gameState = NONE;
            board.updateResults();
        }
    }

    return 0;
}
