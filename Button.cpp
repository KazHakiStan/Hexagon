#include "Button.h"


Button::Button(std::string string, sf::Vector2f pos)
{
    text = string;
    butPos = pos;
}

Button::~Button()
{

}

void Button::draw()
{
    sf::ConvexShape btn;
    btn.setOutlineThickness(2.0f);
    btn.setOutlineColor(sf::Color::Black);
    btn.setPointCount(4);
    btn.setFillColor(sf::Color::White);
    btn.setPoint(0, sf::Vector2f(butPos.x - 3 * window.getSize().x / 20, butPos.y - window.getSize().x / 20));
    btn.setPoint(1, sf::Vector2f(butPos.x - 3 * window.getSize().x / 20, butPos.y + window.getSize().x / 20));
    btn.setPoint(2, sf::Vector2f(butPos.x + 3 * window.getSize().x / 20, butPos.y + window.getSize().x / 20));
    btn.setPoint(3, sf::Vector2f(butPos.x + 3 * window.getSize().x / 20, butPos.y - window.getSize().x / 20));
    window.draw(btn);
    sf::Text btnText = sf::Text(font);
    btnText.setCharacterSize(hexRadius * 0.9);
    btnText.setFillColor(sf::Color::Black);
    btnText.setPosition(sf::Vector2f(butPos.x - 2.5 * hexRadius, butPos.y - hexRadius / 2));
    btnText.setString(text);
    window.draw(btnText);
}

sf::Vector2f Button::getPos()
{
    return butPos;
}

std::string Button::getText()
{
    return text;
}

void Button::setPos(sf::Vector2f pos) {
    butPos = pos;
}


