#ifndef HEX_BOARD_H
#define HEX_BOARD_H
#include "iostream"
#include "fstream"
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "Hex.h"
#include "PlayerColor.h"
#include "Button.h"


class Board {
private:
    float bx = window.getSize().x / 2;
    float by = hexRadius * 3;
    std::vector<Hex *> board = {};
    sf::Vector2i score = {3, 3};
    Hex * currentHex = nullptr;
    bool vsComp = false;
    std::array<Button*, 11> buttons;
    std::vector<Button*> saveBtns;
public:
    Board();
    ~Board();
    /**
     * @brief Resetting board to a initial state.
     */
    void resetBoard();
    /**
     * @brief Saving game to a file.txt.
     * @param fileName name of the file where to save.
     * @param board board object to be saved.
     */
    void saveGame(const std::string& fileName, std::vector<Hex*> board);
    /**
     * @brief Loading game form file.txt.
     * @param fileName name of the file to load.
     */
    void loadGame(const std::string& fileName);
    /**
     * @brief Loading results from results.txt to a global variable results.
     */
    void loadResults();
    /**
     * @brief Updating results file and global variable results.
     */
    void updateResults();
    /**
    * @brief Resizes all elements (buttons, hexes, pawns, etc).
    */
    void resizeBoard();
    /**
    * @brief Handles input of the user.
    */
    void handleInput();
    /**
     * @brief Makes move form hex h1 to hex h2.
     * @param h1 Hex from to make a move.
     * @param h2 Hex where to make a move.
     */
    void makeMove(Hex* h1, Hex* h2);
    /**
     * @brief Highlights/dehighlights possible moves.
     * @param hex
     */
    void highlightHexes(Hex* hex);
    /**
    * @brief Draws score.
    */
    void drawScore();
    /**
    * @brief Draws hexes and pawns.
    */
    void drawBoard();
    /**
    * @brief Renders different menus.
    */
    void render();
    /**
     * @briefCounts pawns of the opponent.
     * @param hex Hex around which there can be enemy pawns.
     * @return Possible count of enemy pawns.
     */
    int countTargetPawns(Hex* hex);
    /**
     * @brief Computes best move for computer.
     * @return Returns pair of hexes for makeMove().
     */
    std::pair<Hex*, Hex*> compMove();
    /**
     * @brief Checks if there is at least one possible move for player.
     * @param player Player to be checked.
     * @return True if there is at least on move.
     */
    bool possibleMoves(PlayerColor player);
    /**
     * @brief Checks if game is over.
     * @return True if game over conditions fulfilled.
     */
    bool isGameOver();
    /**
     * @brief Checks if move is valid.
     * @param h1 Hex from to move.
     * @param h2 Hex where to move.
     * @return True if move is valid.
     */
    bool isValidMove(Hex* h1, Hex* h2);
    /**
     * @brief Checks if jump is valid.
     * @param h1 Hex from to move.
     * @param h2 Hex where to move.
     * @return True if jump is valid.
     */
    bool isValidJump(Hex* h1, Hex* h2);
    bool isClickableArea(int cx, int cy, int r, int x, int y);
    bool isClickableButton(int cx, int cy, int x, int y);

    std::pair<std::vector<Hex*>, std::vector<Hex*>> getMoves(Hex* hex);
    std::vector<Hex*> getAdjHexesWithPawns(Hex* hex);
    std::vector<std::string> getSaveGames();
    sf::Vector2i getScore();
    std::vector<Button*> getSaveBtns();

    void setSaveBtns();
    void setOpponent(bool b);
};

//std::istream& operator >> (std::istream& in, Board& obj);
//std::ostream& operator << (std::ostream& out, Board& obj);

#endif //HEX_BOARD_H
