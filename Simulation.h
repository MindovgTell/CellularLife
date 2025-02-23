#pragma once

#include <vector>
#include <ctime>
#include <strstream>

#include "Grid.h"

class Simulation
{
private:
    sf::VideoMode videoMode;
    sf::RenderWindow* window;

    sf::Font font;
    sf::Text text;
    sf::Text speedText;

    Grid grid;

    sf::Vector2i mousePos;
    sf::Vector2f mouseView;

    int speed;
    sf::Event event;
    bool endSimulation;
    bool isPouse;

    void initWindow();
    void initVariables();
    void initFont();
    void intiText();

public:
    Simulation();
    ~Simulation();

    const bool running() const;

    void updateMouse();

    void updateGui();
    void renderGui();

    void pollEvent();
    void update();
    void render();
};

