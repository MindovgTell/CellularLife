#include "Simulation.h"


void Simulation::initVariables()
{
    this->endSimulation = false;
    this->isPouse = true;
    this->speed = 5;
}

void Simulation::initWindow()
{
    this->videoMode.width = 1000;
    this->videoMode.height = 800;
    this->window = new sf::RenderWindow(this->videoMode, "Life", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

void Simulation::initFont()
{
    if(!this->font.loadFromFile("../Pixelify_Sans/PixelifySans-VariableFont_wght.ttf"))
        std::cout << "ERROR::GAME::INITFONTS::COULD NOT LOAD Jersey_25/Jersey25-Regular.ttf" << '\n';
}

void Simulation::intiText()
{
    //Pause
    this->text.setFont(this->font);
    this->text.setFillColor(sf::Color::Red);
    this->text.setCharacterSize(90);
    this->text.setPosition(sf::Vector2f(370.f,20.f));
    this->text.setString("PAUSE");

    //Speed
    this->speedText.setFont(this->font);
    this->speedText.setFillColor(sf::Color::Red);
    this->speedText.setCharacterSize(50);
    this->speedText.setPosition(sf::Vector2f(20.f,20.f));
}

void Simulation::updateGui()
{
    std::stringstream ss;
    ss << "X" << this->speed << '\n';
    this->speedText.setString(ss.str());
}

void Simulation::renderGui()
{
    if(this->isPouse) this->window->draw(this->text);
    this->window->draw(this->speedText);
}

void Simulation::updateMouse()
{
    this->mousePos = sf::Mouse::getPosition(*this->window);
    this->mouseView = this->window->mapPixelToCoords(this->mousePos);
}

void Simulation::pollEvent()
{
    while(this->window->pollEvent(this->event))
    {
        switch(this->event.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if(this->event.key.code == sf::Keyboard::Escape)
                this->window->close();
            else if(this->event.key.code == sf::Keyboard::P)
            {
                if(this->isPouse) this->isPouse = false;
                else this->isPouse = true;
            }
            else if(this->event.key.code == sf::Keyboard::Left)
            {
                if(speed <= 10 && speed > 1)
                    speed -= 1;
            }
            else if(this->event.key.code == sf::Keyboard::Right)
            {   
                if(speed >= 1 && speed < 10)
                    speed += 1;
            }
            else if(this->event.key.code == sf::Keyboard::R)
            {
                this->grid.reset();
            }
            else if(this->event.key.code == sf::Keyboard::C)
            {
                this->grid.clean();
            }
            break;
        default:
            break;
        }
    }
}

void Simulation::update()
{
    this->pollEvent();
    if(this->endSimulation == false)
    {
        this->updateMouse();
        this->updateGui();
        this->grid.updateGrid(this->mouseView, this->isPouse, this->speed);
    }
}

void Simulation::render()
{
    this->window->clear();

    this->grid.renderGrid(this->window);
    renderGui();

    this->window->display();
}

const bool Simulation::running() const 
{
    return this->window->isOpen(); 
}

Simulation::Simulation()
{
    this->initVariables();
    this->initWindow();
    this->initFont();
    this->intiText();
}

Simulation::~Simulation()
{
    delete this->window;
}