#ifndef HEX_BUTTON_H
#define HEX_BUTTON_H
#include "iostream"
#include "SFML/Graphics.hpp"
#include "Globals.h"


class Button {
private:
    std::string text;
    sf::Vector2f butPos;
public:
    /**
     * @brief Constructor
     * @param string
     * @param pos
     */
    Button(std::string string, sf::Vector2f pos);
    ~Button();
    /**
    * @brief Draws a button.
    */
    void draw();
    /**
     * @brief Get position of button.
     * @return sf::Vector2f of button position.
     */
    sf::Vector2f getPos();
    /**
     * @brief Get button text.
     * @return std::string of button.
     */
    std::string getText();
    /**
    *
    * @param pos sf::Vector2f of button position.
    */
    void setPos(sf::Vector2f pos);
};


#endif //HEX_BUTTON_H
