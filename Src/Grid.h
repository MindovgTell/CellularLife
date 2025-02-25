#pragma once 

#include "Cell.h"

#include <chrono>
#include <thread>
#include <vector>

class Grid
{
private:
    int height, width;
    std::vector< std::vector<Cell> > grid;
    std::vector< std::vector<Cell> > nextGrid;

    bool mouseHeld;
    bool isPouse;

    void initVariables();
    void initGrid();
public:
    //Constructor and destructor
    Grid();
    ~Grid();

    //Accesors
    const int getHeight() const;
    const int getWidth() const;

    //Life stuff
    int neighborsScore(int i, int j);

    void reset();
    void clean();

    void renderGrid(sf::RenderTarget* target);
    void updateGrid(const sf::Vector2f& mousePosition, bool pouse, int n);
};

