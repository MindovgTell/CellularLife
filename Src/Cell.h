#pragma once
#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

class Cell
{
private:
    float size;

    bool is_alive;

    sf::RectangleShape shape;
    sf::Vector2i grid_position;
    sf::Vector2f position;

    void initVariables();
    void initShape();
public:
    //Constructor and Destructor
    Cell();
    ~Cell();

    //Accesors
    const float getSize() const;

    sf::Vector2i getGridPosition();
    void setGridPosition(int x, int y);

    void setPosition(float x, float y);
    sf::Vector2f getPosition();

    //Ugly
    sf::RectangleShape& getShape();


    //Functions
    bool get_state();
    void kill();
    void resurrect();

    void renderCell(sf::RenderTarget* target);
};

