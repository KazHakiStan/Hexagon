#ifndef HEX_MENU_H
#define HEX_MENU_H
#include "SFML/Graphics.hpp"

#define numberOfButtons 11

class Menu {
public:
    Menu(float w, float h);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MouseDown();
private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[numberOfButtons];
};


#endif //HEX_MENU_H
