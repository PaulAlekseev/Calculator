#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <typeinfo>

#include "arrays.h"


void drawButton(sf::Vector2f size, int X, int Y, std::string str, sf::Text text, sf::Font font, sf::RenderWindow* window)
{
    sf::RectangleShape shape(size);
    shape.move(X, Y);
    text.setString(str);
    text.setScale(1.5, 1.5);
    text.setPosition(X + (size.x / 2 - 8), Y + (size.y / 2 - 32));
    shape.setOutlineColor(sf::Color(211, 211, 211));
    shape.setOutlineThickness(1.5);
    window->draw(shape);
    window->draw(text);
}

void drawNumber(int X, int Y, int number, sf::Text text, sf::Font font, sf::RenderWindow* window)
{
    
    std::string num = std::to_string(number);
    text.setString (num);
    text.setScale(1.5, 3);
    text.setPosition(X - text.getLocalBounds().width * 1.5 - 30, Y);
    window->draw(text);
}


int main()
{
    sf::Text text;
    sf::Font font;
    font.loadFromFile("font/ostrich-regular.ttf");
    sf::VideoMode mode(400, 700);
    sf::Vector2f size(100, 100);
    sf::RenderWindow* window;
    window = new sf::RenderWindow (mode, "Calculator");
    window->setFramerateLimit(30);
    sf::Vector2i pos;
    int stage = 0;
    long long number1 = 0;
    long long number2 = 0;
    bool minus1 = false;
    bool minus2 = false;
    int result;
    std::string operation;
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    while (window->isOpen())
    {
        //poll event
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) window->close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                pos = sf::Mouse::getPosition(*window);
                if (pos.x < vectorthingsX[6] + 100 && pos.x > vectorthingsX[6])
                {
                    if (pos.y < vectorthingsY[6] + 100 && pos.y > vectorthingsY[6])
                    {
                        number1 = 0;
                        number2 = 0;
                        stage = 0;
                    }
                }
                switch (stage)
                {
                    case 0:
                        if (pos.x < 300 && pos.y > 300)
                        {
                            for (int i = 0; i < vectornumstrings.size(); i++)
                            {
                                if (pos.x < vectornumsX[i] + 100 && pos.x > vectornumsX[i])
                                {
                                    if (pos.y < vectornumsY[i] + 100 && pos.y > vectornumsY[i])
                                    {
                                        if (!minus1)
                                        {
                                            number1 = number1 * 10;
                                            number1 += vectornums[i];
                                        }
                                        else
                                        {
                                            number1 = number1 * 10;
                                            number1 -= vectornums[i];
                                        }                                  
                                    }
                                }
                            }
                        }
                        if (pos.x < vectorthingsX[0] + 100 && pos.x > vectorthingsX[0])
                        {
                            if (pos.y < vectorthingsY[0] + 100 && pos.y > vectorthingsY[0])
                            {
                                number1 = -number1;
                                if (minus1)
                                {
                                    minus1 = false;
                                }
                                else
                                {
                                    minus1 = true;
                                }  
                            }
                        }
                        if ((pos.x > 300 && pos.x < 400 && pos.y < 600 && pos.y > 200))
                        {
                            for (int i = 0; i < vectornumstrings.size(); i++)
                            {
                                if (pos.x < vectorthingsX[i] + 100 && pos.x > vectorthingsX[i])
                                    {
                                        if (pos.y < vectorthingsY[i] + 100 && pos.y > vectorthingsY[i])
                                        {
                                            operation = vectorthings[i];
                                            stage ++;
                                        }
                                    }
                            }
                        }
                        if (pos.x < vectorthingsX[7] + 100 && pos.x > vectorthingsX[7])
                        {
                            if (pos.y < vectorthingsY[7] + 100 && pos.y > vectorthingsY[7])
                            {
                                if (number1 < 10)
                                {
                                    number1 = 0;
                                }
                                else
                                {
                                    number1 = number1 / 10;
                                }
                            }
                        }
                        break;
                    case 1:
                        if (pos.x < 300 && pos.y > 300)
                        {
                            for (int i = 0; i < vectornumstrings.size(); i++)
                            {
                                if (pos.x < vectornumsX[i] + 100 && pos.x > vectornumsX[i])
                                {
                                    if (pos.y < vectornumsY[i] + 100 && pos.y > vectornumsY[i])
                                    {
                                        if (!minus2)
                                        {
                                            number2 = number2 * 10;
                                            number2 += vectornums[i];
                                        }
                                        else
                                        {
                                            number2 = number2 * 10;
                                            number2 -= vectornums[i];
                                        }                                        
                                    }
                                }
                            }
                        }
                        if (pos.x < vectorthingsX[0] + 100 && pos.x > vectorthingsX[0])
                        {
                            if (pos.y < vectorthingsY[0] + 100 && pos.y > vectorthingsY[0])
                            {
                                number2 = -number2;
                                if (minus2)
                                {
                                    minus2 = false;
                                }
                                else
                                {
                                    minus2 = true;
                                }   
                            }
                        }
                        if (pos.x < vectorthingsX[2] + 100 && pos.x > vectorthingsX[2])
                        {
                            if (pos.y < vectorthingsY[2] + 100 && pos.y > vectorthingsY[2])
                            {
                                if (operation == "+") result = number1 + number2;
                                if (operation == "-") result = number1 - number2;
                                if (operation == "x") result = number1 * number2;
                                if (operation == "/") result = number1 / number2;
                                number1 = result;
                                number2 = 0;
                                stage--;
                            }
                        }
                        if (pos.x < vectorthingsX[7] + 100 && pos.x > vectorthingsX[7])
                        {
                            if (pos.y < vectorthingsY[7] + 100 && pos.y > vectorthingsY[7])
                            {
                                if (number2 < 10)
                                {
                                    number2 = 0;
                                }
                                else
                                {
                                    number2 = number2 / 10;
                                }
                            }
                        }
                        break;
                }
            }
        }

        window->clear(sf::Color(211, 211, 211));
        drawNumber(400, 0, number1, text, font, window);
        if (stage == 1)
        {
            text.setPosition(200, 50);
            text.setString(operation);
            text.setScale(2, 2);
            window->draw(text);
            drawNumber(400, 100, number2, text, font, window);
        }
        for (int i = 0; i < vectornumstrings.size(); i++)
        {
            drawButton(size, vectornumsX[i], vectornumsY[i], vectornumstrings[i], text, font, window);
        }
        for (int i = 0; i < vectorthings.size(); i++)
        {
            drawButton(size, vectorthingsX[i], vectorthingsY[i], vectorthings[i], text, font, window);
        }
        window->display();
    }
}
