#include "Grid.h"


void Grid::initVariables()
{
    this->height = 200;
    this->width = 160;
    this->mouseHeld = false;
}

void Grid::initGrid()
{
    Cell cell;
    grid.resize(height, std::vector<Cell>(width, cell));
    nextGrid.resize(height, std::vector<Cell>(width, cell));
    for(int i = 0; i < height; ++i)
    {
        int x = i*5.0f;
        for(int j = 0; j < width; ++j)
        {
            int y = j*5.0f;
            grid[i][j].setPosition(x,y);
            nextGrid[i][j].setPosition(x,y);
            if(rand()%10 + 1 < 3)
                grid[i][j].resurrect();
        }
    }
}

void Grid::reset()
{
    for(int i = 0; i < height; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            grid[i][j].kill();
            if(rand()%10 + 1 < 3)
                grid[i][j].resurrect();
        }
    }
}

void Grid::clean()
{
    for(int i = 0; i < height; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            grid[i][j].kill();
        }
    }
}   

int Grid::neighborsScore(int row, int col)
{
    //UDB if i = 0 , j = 0 
    // you have to fix it 
    int score = 0;
    int dirRow[8] = {1,-1,1,-1,1,-1,0,0};
    int dirCol[8] = {-1,-1,1,1,0,0,1,-1};

    for(int n = 0; n < 8; ++n)
    {
        int neighborRow = row + dirRow[n];
        int neighborCol = col + dirCol[n];
        if(neighborRow < 0 || neighborRow > height - 1 || neighborCol < 0 || neighborCol > width -1)
            continue;
        if(this->grid[neighborRow][neighborCol].get_state()) score++;
    }
    return score;
}

void Grid::updateGrid(const sf::Vector2f& mousePosition, bool pouse, int speed)
{
    if(pouse)
    {
        std::this_thread::sleep_for(std::chrono::nanoseconds(50000000));
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if(this->mouseHeld == false)
            { 
                this->mouseHeld = true;
                for(size_t i = 0; i < height; ++i)
                {
                    for(size_t j = 0; j < width; ++j)
                    {
                        if(grid[i][j].getShape().getGlobalBounds().contains(mousePosition))
                        {
                            grid[i][j].get_state() ? grid[i][j].kill() : grid[i][j].resurrect();
                        }
                    }
                }  
            }
            else this->mouseHeld = false;
        }
    }
    else
    {
    //Life stuff

        //std::this_thread::sleep_for(std::chrono::nanoseconds(1000000000/speed));
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                if(grid[i][j].get_state() == true && neighborsScore(i,j) < 2) 
                    nextGrid[i][j].kill();
                else if(grid[i][j].get_state() == true && neighborsScore(i,j) > 3) 
                    nextGrid[i][j].kill();
                else if(grid[i][j].get_state() == false && neighborsScore(i,j) == 3)
                    nextGrid[i][j].resurrect();
                else nextGrid[i][j] = grid[i][j];
            } 
        }

        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                grid[i][j] = nextGrid[i][j];
            }
        }
    }
}

void Grid::renderGrid(sf::RenderTarget* target)
{
    for(int i = 0; i < height; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            this->grid[i][j].renderCell(target);
        }
    }
}

Grid::Grid()
{
    this->initVariables();
    this->initGrid();
}

Grid::~Grid()
{
}

const int Grid::getHeight() const 
{
    return this->height;
}

const int Grid::getWidth() const
{
    return this->width;
}
