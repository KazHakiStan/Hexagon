#include "Board.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include "Globals.h"
#include "PlayerColor.h"
#include "Pawn.h"
#include "Hex.h"
#include <cstdio>
#include <fstream>

Board::Board()
{
    for (int i = 0; i < BoardHeight; i++) {
        float temp = bx;
        for (int j = 0; j < BoardWidth; j++) {
            if (boardScheme[i][j] == 1) {
                if (
                        (i == 0 && j == 4) ||
                        (i == 12 && j == 0) ||
                        (i == 12 && j == 8))
                {
                    board.push_back(new Hex(temp, by, i, j, new Pawn(BLUE)));
                }
                else if (
                        (i == 4 && j == 0) ||
                        (i == 4 && j == 8) ||
                        (i == 16 && j == 4))
                {
                    board.push_back(new Hex(temp, by, i, j, new Pawn(RED)));
                }
                else board.push_back(new Hex(temp, by, i, j));
                temp += 3 * hexWidth / 2;
            }
            else if ((i == 6 && j == 4) || (i == 9 && j == 3) || (i == 9 && j == 5)) {
                temp += 3 * hexWidth / 2;
            }
        }
        by += hexHeight / 2;
        if (i < 4 || (i < 12 && i % 2 != 0)) {
            bx -= 3 * hexWidth / 4;
            continue;
        }
        else {
            bx += 3 * hexWidth / 4;
            continue;
        }
    }
    buttons[0] = new Button("New Game", sf::Vector2f (window.getSize().x / 2, window.getSize().y * 7 / 20 ));
    buttons[1] = new Button("Continue", sf::Vector2f (window.getSize().x / 2, window.getSize().y * 5 / 20 ));
    buttons[2] = new Button("Save Game", sf::Vector2f (window.getSize().x / 2, window.getSize().y * 9 / 20 ));
    buttons[3] = new Button("Load Game", sf::Vector2f (window.getSize().x / 2, window.getSize().y * 11 / 20 ));
    buttons[4] = new Button("High Scores", sf::Vector2f (window.getSize().x / 2, window.getSize().y * 13 / 20 ));
    buttons[5] = new Button("Human VS Human", sf::Vector2f (window.getSize().x / 2, window.getSize().y * 9 / 20 ));
    buttons[6] = new Button("Human VS Computer", sf::Vector2f (window.getSize().x / 2, window.getSize().y * 11 / 20 ));
    buttons[7] = new Button("Menu", sf::Vector2f (window.getSize().x / 2, window.getSize().y * 19 / 20 ));
    buttons[8] = new Button("Exit", sf::Vector2f (window.getSize().x / 2, window.getSize().y * 15 / 20 ));
    buttons[9] = new Button("Yes", sf::Vector2f (window.getSize().x / 2 - 3 * window.getSize().x / 20, window.getSize().y * 15 / 20 ));
    buttons[10] = new Button("No", sf::Vector2f (window.getSize().x / 2 + 3 * window.getSize().x / 20, window.getSize().y * 15 / 20 ));
    setSaveBtns();
}

Board::~Board()
{

}

void Board::resetBoard()
{
    float rbx = window.getSize().x / 2;
    float rby = hexRadius * 3;
    std::vector<Hex*>::iterator it = board.begin();
    for (int i = 0; i < BoardHeight; i++) {
        float temp = rbx;
        for (int j = 0; j < BoardWidth; j++) {
            if (boardScheme[i][j] == 1) {
                if ((i == 0 && j == 4) || (i == 12 && j == 0) || (i == 12 && j == 8))
                    (*it++)->setPawn(new Pawn(BLUE));
                else if ((i == 4 && j == 0) || (i == 4 && j == 8) || (i == 16 && j == 4))
                    (*it++)->setPawn(new Pawn(RED));
                else (*it++)->setPawn(nullptr);
                temp += 3 * hexWidth / 2;
            } else if ((i == 6 && j == 4) || (i == 9 && j == 3) || (i == 9 && j == 5))
            {
                temp += 3 * hexWidth / 2;
            }
        }
        rby += hexHeight / 2;
        if (i < 4 || (i < 12 && i % 2 != 0)) {
            rbx -= 3 * hexWidth / 4;
            continue;
        }
        else {
            rbx += 3 * hexWidth / 4;
            continue;
        }
    }
    currentPlayer = RED;
    score.x = 3;
    score.y = 3;
}

void Board::resizeBoard() {
    float rbx = window.getSize().x / 2;
    float rby = hexRadius * 3;
    std::vector<Hex*>::iterator it = board.begin();
    for (int i = 0; i < BoardHeight; i++) {
        float temp = rbx;
        for (int j = 0; j < BoardWidth; j++) {
            if (boardScheme[i][j] == 1) {
                (*it++)->setPos(temp, rby);
                temp += 3 * hexWidth / 2;
            } else if ((i == 6 && j == 4) || (i == 9 && j == 3) || (i == 9 && j == 5))
            {
                temp += 3 * hexWidth / 2;
            }
        }
        rby += hexHeight / 2;
        if (i < 4 || (i < 12 && i % 2 != 0)) {
            rbx -= 3 * hexWidth / 4;
            continue;
        }
        else {
            rbx += 3 * hexWidth / 4;
            continue;
        }
    }
    buttons[0]->setPos(sf::Vector2f (window.getSize().x / 2, window.getSize().y * 7 / 20 ));
    buttons[1]->setPos(sf::Vector2f (window.getSize().x / 2, window.getSize().y * 5 / 20 ));
    buttons[2]->setPos(sf::Vector2f (window.getSize().x / 2, window.getSize().y * 9 / 20 ));
    buttons[3]->setPos(sf::Vector2f (window.getSize().x / 2, window.getSize().y * 11 / 20 ));
    buttons[4]->setPos(sf::Vector2f (window.getSize().x / 2, window.getSize().y * 13 / 20 ));
    buttons[5]->setPos(sf::Vector2f (window.getSize().x / 2, window.getSize().y * 9 / 20 ));
    buttons[6]->setPos(sf::Vector2f (window.getSize().x / 2, window.getSize().y * 11 / 20 ));
    buttons[7]->setPos(sf::Vector2f (window.getSize().x / 2, window.getSize().y * 19 / 20 ));
    buttons[8]->setPos(sf::Vector2f (window.getSize().x / 2, window.getSize().y * 15 / 20 ));
    buttons[9]->setPos(sf::Vector2f (window.getSize().x / 2 - 3 * window.getSize().x / 20, window.getSize().y * 15 / 20 ));
    buttons[10]->setPos(sf::Vector2f (window.getSize().x / 2 + 3 * window.getSize().x / 20, window.getSize().y * 15 / 20 ));
    setSaveBtns();
}

void Board::saveGame(const std::string& fileName, std::vector<Hex*> board)
{
    std::ofstream file(saveFolder + fileName);
    if (file.is_open())
    {
        for (Hex* h : board)
        {
            if (h->getPawn() == nullptr) file << "0 ";
            else if (h->getPawn()->getPlayer() == RED) file << "1 ";
            else file << "2 ";
        }
        if (currentPlayer == RED) file << "1 ";
        else file << "2 ";
        if (vsComp == true) file << "1";
        else file << "0";
        file.close();
        std::cout << "File saved successfully!" << std::endl;
    }
    else
    {
        std::cout << "Failed to save file." << std::endl;
    }
}

void Board::loadGame(const std::string& fileName)
{
    std::ifstream file(saveFolder + fileName);
    if (file.is_open())
    {
        std::string data;
        while (std::getline(file, data))
        {
//            std::cout << data << std::endl;
        }
        file.close();
//        std::cout << "File loaded successfully!" << std::endl;
        std::istringstream iss(data);
        std::vector<std::string> lines;
        std::string line;
        while (iss >> line)
        {
            lines.push_back(line);
        }
        if (lines.size() != board.size() + 1) std::cout << "Failed to load a file" << std::endl;

        int i = 0;
        score.x = 0;
        score.y = 0;
        for (std::string l : lines)
        {
            if (i == board.size())
            {
                currentPlayer = (l == "1") ? RED : BLUE;
                i++;
                continue;
            }
            if (i == board.size() + 1)
            {
                vsComp = (l == "1") ? true : false;
                break;
            }
            if (l == "0")
            {
                if (board[i]->getPawn() != nullptr)
                {
                    delete board[i]->getPawn();
                    board[i]->setPawn(nullptr);
                }
            } else if (l == "1")
            {
                if (board[i]->getPawn() == nullptr)
                    board[i]->setPawn(new Pawn(RED));
                else if (board[i]->getPawn()->getPlayer() == BLUE)
                    board[i]->getPawn()->setPlayer(RED);
                score.x += 1;
            } else if (l == "2")
            {
                if (board[i]->getPawn() == nullptr)
                    board[i]->setPawn(new Pawn(BLUE));
                else if (board[i]->getPawn()->getPlayer() == RED)
                    board[i]->getPawn()->setPlayer(BLUE);
                score.y += 1;
            }
            i++;
        }
        gameState = GOING;
    }
    else
    {
        std::cout << "Failed to load file." << std::endl;
    }
}

void Board::loadResults()
{
    std::ifstream file("results.txt");
    if (file.is_open())
    {
        std::string data;
        int i = 0;
        while (std::getline(file, data))
        {
            std::istringstream iss(data);
            std::vector<std::string> lines;
            std::string line;
            while (iss >> line)
            {
                lines.push_back(line);
            }
            results[i].first = stoi(lines[0]);
            results[i].second = stoi(lines[1]);
            i++;
        }
        file.close();
    }
    else
    {
        std::cout << "Failed to load results." << std::endl;
    }
}

void Board::updateResults()
{
    const char* resultsFile = "results.txt";
    const char* tempFile = "temp.txt";
    std::ifstream file(resultsFile);
    std::ofstream temp(tempFile);
    bool altScore = false;
    for (int i = 0; i < 5; i++)
    {
        if (results[i].first == 0 && results[i].second == 0)
        {
            results[i].first = score.x;
            results[i].second = score.y;
            std::cout << "new score set " << results[i].first << " : " << results[i].second << std::endl;
            break;
        }

        for (int j = 0; j < 5; j++)
        {
            if (results[j].first == 0 && results[j].second == 0)
            {
                altScore = true;
                break;
            }
        }

        if (abs(results[i].first - results[i].second) < abs(score.x - score.y) && !altScore)
        {
            results[i].first = score.x;
            results[i].second = score.y;
            std::cout << "new score set " << results[i].first << " : " << results[i].second << std::endl;
            break;
        }


    }
    if (file.is_open() && temp.is_open())
    {
        std::cout << "cs1. " << std::endl;
        std::string line;
        for (int i = 0; i < 5; i++)
        {
            temp << std::to_string(results[i].first) + " " + std::to_string(results[i].second) << std::endl;
        }
        file.close();
        temp.close();
        if (std::remove(resultsFile) == 0 && std::rename(tempFile, resultsFile) == 0) {
            std::cout << "File rewritten successfully." << std::endl;
        } else {
            std::cerr << "Failed to replace the file." << std::endl;
        }
    }
    else
    {
        std::cout << "Failed to load results." << std::endl;
    }
}

void Board::handleInput() {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::MouseButtonPressed) {
            auto mx = sf::Mouse::getPosition(window).x;
            auto my = sf::Mouse::getPosition(window).y;
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                if (menuState == GAME)
                {
                    if (isClickableButton(mx, my, buttons[7]->getPos().x, buttons[7]->getPos().y))
                    {
                        menuState = MAIN;
                        return;
                    }
                    Hex* clickedHex = nullptr;
                    for (Hex* hex : board) {
                        if (isClickableArea(mx, my, hexHeight / 2, hex->getPos().x, hex->getPos().y))
                        {
                            clickedHex = hex;
                            break;
                        }
                    }
                    if (clickedHex == nullptr) return;
                    if (currentHex == nullptr)
                    {
                        if (
                                clickedHex->getPawn() != nullptr
                                && clickedHex->getPawn()->getPlayer() == currentPlayer)
                        {
                            clickedHex->setState(true);
                            currentHex = clickedHex;
                            highlightHexes(clickedHex);
                        }
                    } else
                    {
                        if (clickedHex == currentHex)
                        {
                            clickedHex->setState(false);
                            currentHex = nullptr;
                            highlightHexes(clickedHex);
                        } else
                        {
                            makeMove(currentHex, clickedHex);
                        }
                    }
                    clickedHex = nullptr;
                } else if (menuState == MAIN)
                {
                    if (isClickableButton(mx, my, buttons[0]->getPos().x, buttons[0]->getPos().y))
                    {
                        menuState = START;
                        return;
                    } else if (isClickableButton(mx, my, buttons[1]->getPos().x, buttons[1]->getPos().y))
                    {
                        menuState = GAME;
                        return;
                    } else if (isClickableButton(mx, my, buttons[2]->getPos().x, buttons[2]->getPos().y))
                    {
                        menuState = SAVE;
                        return;
                    } else if (isClickableButton(mx, my, buttons[3]->getPos().x, buttons[3]->getPos().y))
                    {
                        menuState = LOAD;
                        return;

                    } else if (isClickableButton(mx, my, buttons[4]->getPos().x, buttons[4]->getPos().y))
                    {
                        menuState = SCORES;
                        return;
                    } else if (isClickableButton(mx, my, buttons[8]->getPos().x, buttons[8]->getPos().y))
                    {
                        menuState = EXIT;
                        return;
                    }
                } else if (menuState == START)
                {
                    if (isClickableButton(mx, my, buttons[5]->getPos().x, buttons[5]->getPos().y))
                    {
                        menuState = GAME;
                        setOpponent(false);
                        gameState = GOING;
                        resetBoard();
                        return;
                    } else if (isClickableButton(mx, my, buttons[6]->getPos().x, buttons[6]->getPos().y))
                    {
                        menuState = GAME;
                        setOpponent(true);
                        gameState = GOING;
                        resetBoard();
                        return;
                    } else if (isClickableButton(mx, my, buttons[7]->getPos().x, buttons[7]->getPos().y))
                    {
                        menuState = MAIN;
                        return;
                    }
                } else if (menuState == SAVE)
                {
                    std::vector<std::string> savedGames = getSaveGames();
                    if (isClickableButton(mx, my, buttons[9]->getPos().x, buttons[9]->getPos().y))
                    {
                        if (!selectedSaveGame.empty())
                        {
                            saveGame(selectedSaveGame + ".txt", board);
                            savedGames = getSaveGames();
                            savedGamesText.setString("");
                            for (const std::string& savedGame : savedGames)
                            {
                                savedGamesText.setString(savedGamesText.getString() + savedGame + "\n");
                            }
                        }
                        selectedSaveGame.clear();
                        inputText.setString("");
                        menuState = MAIN;
                        return;
                    } else if (isClickableButton(mx, my, buttons[10]->getPos().x, buttons[10]->getPos().y))
                    {
                        menuState = MAIN;
                        return;
                    }
                } else if (menuState == LOAD)
                {
                    if (isClickableButton(mx, my, buttons[7]->getPos().x, buttons[7]->getPos().y))
                    {
                        menuState = MAIN;
                        return;
                    }
                    for (Button* b : saveBtns)
                    {
                        if (isClickableButton(mx, my, b->getPos().x, b->getPos().y))
                        {
                            loadGame(b->getText());
                            menuState = GAME;
                            return;
                        }
                    }
                } else if (menuState == SCORES)
                {
                    if (isClickableButton(mx, my, buttons[7]->getPos().x, buttons[7]->getPos().y))
                    {
                        menuState = MAIN;
                        return;
                    }
                }
            }
        } else if (event.type == sf::Event::Resized)
        {
            sf::FloatRect visibleArea({0, 0}, sf::Vector2f(event.size.width, event.size.height));
            if (window.getSize().x > 1080) window.setSize({1080, 1080});
            else if (window.getSize().x < 500) window.setSize({500, 500});
            auto newSize = std::max({window.getSize().y, window.getSize().y});
            window.setSize({newSize, newSize});
            window.setView(sf::View(visibleArea));
            hexRadius = window.getSize().x / 20;
            hexWidth = 2.0f * hexRadius;
            hexHeight = 1.732f * hexRadius;
            pawnRadius = hexRadius * 0.9;
            resizeBoard();
        } else if (event.type == sf::Event::TextEntered)
        {
            if (menuState == SAVE) {
                if (event.text.unicode < 128 && event.text.unicode != '\b' && event.text.unicode != '\r')
                {
                    selectedSaveGame += static_cast<char>(event.text.unicode);
                    inputText.setString(selectedSaveGame);
                }
                else if (event.text.unicode == '\b' && !selectedSaveGame.empty())
                {
                    selectedSaveGame.pop_back();
                    inputText.setString(selectedSaveGame);
                }
            }
        }
    }
}

void Board::makeMove(Hex* h1, Hex* h2)
{
    if (isValidMove(h1, h2))
    {
        h2->setPawn(new Pawn(currentPlayer));
        if (currentPlayer == RED) score.x++;
        else score.y++;
        for (Hex* h : getAdjHexesWithPawns(h2))
            if (h->getPawn()->getPlayer() != currentPlayer)
            {
                h->getPawn()->setPlayer(currentPlayer);
                if (currentPlayer == RED)
                {
                    score.x++;
                    score.y--;
                } else {
                    score.x--;
                    score.y++;
                }
            }
    }
    else if (isValidJump(h1, h2))
    {
        h2->setPawn(h1->getPawn());
        h1->setPawn(nullptr);
        for (Hex* h : getAdjHexesWithPawns(h2))
            if (h->getPawn()->getPlayer() != currentPlayer)
            {
                h->getPawn()->setPlayer(currentPlayer);
                if (currentPlayer == RED)
                {
                    score.x++;
                    score.y--;
                } else {
                    score.x--;
                    score.y++;
                }
            }
    }
    else
    {
        h1->setState(false);
        h2->setState(false);
        currentHex = nullptr;
        highlightHexes(h1);
        return;
    }

    h1->setState(false);
    h2->setState(false);
    currentPlayer = (currentPlayer == RED) ? BLUE : RED;
    currentHex = nullptr;
    highlightHexes(h1);
    if (vsComp && currentPlayer == BLUE) {
        std::pair<Hex*, Hex*> move = compMove();
        makeMove(move.first, move.second);
    }
}

void Board::highlightHexes(Hex* hex)
{
    std::pair<std::vector<Hex*>, std::vector<Hex*>> moves;
    for (sf::Vector2i hexPos : hex->getAdjHexesPos().first){
        for (Hex* h : board) {
            if (h->getBoardPos() == hexPos) moves.first.push_back(h);
        }
    }
    for (sf::Vector2i hexPos : hex->getAdjHexesPos().second){
        for (Hex* h : board) {
            if (h->getBoardPos() == hexPos) moves.second.push_back(h);
        }
    }
    if (!moves.first.empty())
    {
        for (Hex* h : moves.first)
        {
            if (currentHex != nullptr && h->getPawn() == nullptr)
            {
                h->setColor(sf::Color::Green);
            }
            if (currentHex == nullptr)
            {
                hex->setColor(hexColor);
                h->setColor(hexColor);
            }
        }
    }
    if (!moves.second.empty())
    {
        for (Hex* h : moves.second)
        {
            if (currentHex != nullptr && h->getPawn() == nullptr)
            {
                hex->setColor(sf::Color::Yellow);
                h->setColor(sf::Color::Yellow);
            }

            if (currentHex == nullptr)
            {
                hex->setColor(hexColor);
                h->setColor(hexColor);
            }
        }
    }
}

void Board::drawScore() {
    sf::ConvexShape scoreShape;
    scoreShape.setOutlineThickness(2.0f);
    scoreShape.setOutlineColor(sf::Color::Black);
    scoreShape.setPointCount(4);
    scoreShape.setFillColor(sf::Color::Red);
    scoreShape.setPoint(0, sf::Vector2f(0, window.getSize().y / hexRadius));
    scoreShape.setPoint(1, sf::Vector2f(0, 2 * window.getSize().y / hexRadius));
    scoreShape.setPoint(2, sf::Vector2f(window.getSize().x / 10, 2 * window.getSize().y / hexRadius));
    scoreShape.setPoint(3, sf::Vector2f(window.getSize().x / 10, window.getSize().y / hexRadius));
    window.draw(scoreShape);
    scoreShape.setFillColor(sf::Color::Blue);
    scoreShape.setPoint(0, sf::Vector2f(0, window.getSize().y / hexRadius + hexRadius));
    scoreShape.setPoint(1, sf::Vector2f(0, 2 * window.getSize().y / hexRadius + hexRadius));
    scoreShape.setPoint(2, sf::Vector2f(window.getSize().x / 10, 2 * window.getSize().y / hexRadius + hexRadius));
    scoreShape.setPoint(3, sf::Vector2f(window.getSize().x / 10, window.getSize().y / hexRadius + hexRadius));
    window.draw(scoreShape);
    score1.setCharacterSize(hexRadius);
    score1.setFillColor(sf::Color::White);
    score1.setOutlineThickness(1.0f);
    score1.setOutlineColor(sf::Color::Red);
    score1.setPosition(sf::Vector2f(window.getSize().x / 10, window.getSize().y / hexRadius / 2));
    score1.setString(std::to_string(score.x));
    score2.setCharacterSize(hexRadius);
    score2.setFillColor(sf::Color::White);
    score2.setOutlineThickness(1.0f);
    score2.setOutlineColor(sf::Color::Blue);
    score2.setPosition(sf::Vector2f(window.getSize().x / 10, window.getSize().y / hexRadius / 2 + hexRadius));
    score2.setString(std::to_string(score.y));
    window.draw(score1);
    window.draw(score2);
}

void Board::drawBoard()
{
    for (Hex* h : board) {
        h->draw();
    }
}

void Board::render() {
    window.clear(sf::Color::Black);
    sf::Sprite bgSprite(bgTexture);
    bgSprite.setPosition(sf::Vector2f (0, 0));
    bgSprite.setScale(
            sf::Vector2f (1.2,
            1.2)
    );
    window.draw(bgSprite);
    switch (menuState)
    {
        case MAIN:
        {
            if (gameState == GOING) buttons[1]->draw();
            buttons[0]->draw();
            buttons[2]->draw();
            buttons[3]->draw();
            buttons[4]->draw();
            buttons[8]->draw();
            break;
        }
        case START:
        {
            buttons[5]->draw();
            buttons[6]->draw();
            buttons[7]->draw();
            break;
        }
        case GAME:
        {
            drawBoard();
            drawScore();
            buttons[7]->draw();
            break;
        }
        case LOAD:
        {
            setSaveBtns();
            for (Button* b : saveBtns)
            {
                b->draw();
            }
            sf::Text loadText = sf::Text(font);
            loadText.setString("Load");
            loadText.setCharacterSize(window.getSize().x / 50);
            loadText.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
            window.draw(loadText);
            buttons[7]->draw();
            break;
        }
        case SAVE:
        {
            setSaveBtns();
            sf::Text saveText = sf::Text(font);
            inputText.setCharacterSize(window.getSize().x / 50);
            inputText.setFillColor(sf::Color::White);
            inputText.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 3));
            saveText.setString("Save");
            saveText.setCharacterSize(window.getSize().x / 50);
            saveText.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
            window.draw(saveText);
            window.draw(inputText);

            buttons[9]->draw();
            buttons[10]->draw();
            break;
        }
        case SCORES:
        {
            loadResults();
            sf::ConvexShape panel;
            panel.setOutlineThickness(2.0f);
            panel.setOutlineColor(sf::Color::Black);
            panel.setPointCount(4);
            panel.setFillColor(sf::Color::White);
            for (int i = 0; i < 5; i++)
            {
                panel.setPoint(0, sf::Vector2f(window.getSize().x / 3, window.getSize().y / 3 - window.getSize().x / 20 + i * window.getSize().x / 10));
                panel.setPoint(1, sf::Vector2f(window.getSize().x / 3, window.getSize().y / 3 + window.getSize().x / 20 + i * window.getSize().x / 10));
                panel.setPoint(2, sf::Vector2f(2 * window.getSize().x / 3, window.getSize().y / 3 + window.getSize().x / 20 + i * window.getSize().x / 10));
                panel.setPoint(3, sf::Vector2f(2 * window.getSize().x / 3, window.getSize().y / 3 - window.getSize().x / 20 + i * window.getSize().x / 10));
                window.draw(panel);
                sf::Text panelText = sf::Text(font);
                panelText.setCharacterSize(hexRadius * 0.5);
                panelText.setFillColor(sf::Color::Black);
                panelText.setPosition(sf::Vector2f(window.getSize().x / 2 - 2.5 * hexRadius, window.getSize().y / 3 - hexRadius / 2 + i * window.getSize().x / 10));
                panelText.setString("RED - " + std::to_string(results[i].first) + " : " + std::to_string(results[i].second) + " - BLUE");
                window.draw(panelText);
            }
            buttons[7]->draw();
            break;
        }
        case EXIT:
        {
            window.close();
        }
    }
    window.display();
}

int Board::countTargetPawns(Hex* hex)
{
    int count = 0;
    for (Hex* h : getAdjHexesWithPawns(hex))
    {
        if (h->getPawn()->getPlayer() == RED) count++;
    }
    return count;
}

std::pair<Hex*, Hex*> Board::compMove()
{
    int maxTargetPawns = 0;
    int hexTargetPawns;
    std::pair<Hex*, Hex*> bestMove;

    for (Hex* h : board)
    {
        if (h->getPawn() != nullptr && h->getPawn()->getPlayer() == BLUE)
        {
            for (Hex* hex : getMoves(h).second)
            {
                hexTargetPawns = countTargetPawns(hex);
                if (hexTargetPawns >= maxTargetPawns && isValidJump(h, hex))
                {
                    maxTargetPawns = hexTargetPawns;
                    bestMove.first = h;
                    bestMove.second = hex;
                }
            }
            for (Hex* hex : getMoves(h).first)
            {
                hexTargetPawns = countTargetPawns(hex) + 1;
                if (hexTargetPawns >= maxTargetPawns && isValidMove(h, hex))
                {
                    maxTargetPawns = hexTargetPawns;
                    bestMove.first = h;
                    bestMove.second = hex;
                }
            }
        }
    }
    return bestMove;
}

bool Board::possibleMoves(PlayerColor player) {
    for (Hex* h : board) {
        if (
                h->getPawn() != nullptr
                && h->getPawn()->getPlayer() == player
                && (getMoves(h).first.size() != 0 || getMoves(h).second.size() != 0))
            return true;
    }
    return false;
}

bool Board::isGameOver() {
    if (score.x + score.y == board.size() || !possibleMoves(RED) || !possibleMoves(BLUE) || score.x == 0 || score.y == 0) return true;
    return false;
}

bool Board::isValidMove(Hex* h1, Hex* h2)
{
    std::pair<std::vector<Hex*>, std::vector<Hex*>> moves = getMoves(h1);
//    if (moves.first.empty()) {
//        std::cout<<"GOVNO " << h1 << std::endl;
//    }
    for (Hex* hex : moves.first)
    {
        if (hex == h2)
        {
            return true;
        }
    }
    return false;
}

bool Board::isValidJump(Hex* h1, Hex* h2)
{
    for (Hex* hex : getMoves(h1).second)
    {
        if (hex == h2)
        {
            return true;
        }
    }
    return false;
}

bool Board::isClickableArea(int cx, int cy, int r, int x, int y)
{
    int dist = (x - cx) * (x - cx) + (y - cy) * (y - cy);
    if ( dist <= r * r)
        return true;
    else
        return false;
}

bool Board::isClickableButton(int cx, int cy, int x, int y)
{
    if (
            cx > x - 3 * window.getSize().x / 20 && cx < x + 3 * window.getSize().x / 20
            && cy > y - window.getSize().x / 20 && cy < y + window.getSize().x / 20)
    {
        return true;
    } else
        return false;
}

std::pair<std::vector<Hex*>, std::vector<Hex*>> Board::getMoves(Hex* hex)
{
    std::pair<std::vector<Hex*>, std::vector<Hex*>> moves;
    for (sf::Vector2i hexPos : hex->getAdjHexesPos().first)
    {
        for (Hex* h : board)
        {
            if (h->getBoardPos() == hexPos && h->getPawn() == nullptr)
            {
                moves.first.push_back(h);
//                    std::cout << "added move " << h << " for " << hex << std::endl;
            }
        }
    }
    for (sf::Vector2i hexPos : hex->getAdjHexesPos().second)
    {
        for (Hex* h : board)
        {
            if (h->getBoardPos() == hexPos && h->getPawn() == nullptr) {
                moves.second.push_back(h);
//                    std::cout << "added jump " << &h << " for " << hex << std::endl;
            }
        }
    }
    return moves;
}

std::vector<Hex*> Board::getAdjHexesWithPawns(Hex* hex) {
    std::vector<Hex*> adjHexesWithPawns;
    for (sf::Vector2i hexPos : hex->getAdjHexesPos().first) {
        for (Hex* h : board) {
            if (h->getBoardPos() == hexPos && h->getPawn() != nullptr)
                adjHexesWithPawns.push_back(h);
        }
    }
    return adjHexesWithPawns;
}

std::vector<std::string> Board::getSaveGames()
{
    std::vector<std::string> savedGames;
    for (const auto& entry : std::filesystem::directory_iterator(saveFolder))
    {
        savedGames.push_back(entry.path().filename().string());
    }
    return savedGames;
}

sf::Vector2i Board::getScore() {
    return score;
}

std::vector<Button*> Board::getSaveBtns()
{
    return saveBtns;
}

void Board::setSaveBtns()
{
    std::vector<std::string> savedGames = getSaveGames();
    int i = 0;
    for (const std::string& savedGame : savedGames)
    {
        while (i < savedGames.size())
        {
            saveBtns.push_back(new Button(savedGame, sf::Vector2f(3 * window.getSize().x / 4, 1 * window.getSize().y / 5 + i++ * window.getSize().y / 10)));
            break;
        }
    }
}

void Board::setOpponent(bool b)
{
    vsComp = b;
}
