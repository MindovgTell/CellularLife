#include "Cell.h"

void Cell::initVariables()
{
    this->is_alive = false;
    this->size = 10.f;
    this->position = sf::Vector2f(0.f,0.f);
}

void Cell::initShape()
{
    this->shape.setFillColor(sf::Color::White);
    this->shape.setSize(sf::Vector2f(this->size, this->size));
    this->shape.setOutlineColor(sf::Color(169,169,169));
    this->shape.setOutlineThickness(1);
    this->shape.setPosition(0.f,0.f);
}

Cell::Cell()
{ 
    this->initVariables();
    this->initShape();
}

Cell::~Cell()
{
}

sf::RectangleShape& Cell::getShape()
{
    return this->shape;
}

const float Cell::getSize() const
{
    return this->size;
}

sf::Vector2i Cell::getGridPosition()
{
    return this->grid_position;
}

void Cell::setGridPosition(int x, int y)
{
    this->grid_position = sf::Vector2i(x,y);
}

void Cell::setPosition(float x, float y)
{
    this->shape.setPosition(x,y);
    this->position = sf::Vector2f(x,y);
}

sf::Vector2f Cell::getPosition()
{
    return this->position;
}

bool Cell::get_state()
{
    return this->is_alive;
}

void Cell::resurrect()
{
    this->is_alive = true;
    this->shape.setFillColor(sf::Color::Black);
}

void Cell::kill()
{
    this->is_alive = false;
    this->shape.setFillColor(sf::Color::White);
}

void Cell::renderCell(sf::RenderTarget* target)
{
    target->draw(this->shape);
}