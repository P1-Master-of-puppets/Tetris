#include "game.h"

Game::Game()
{
}

Game::~Game()
{
}

Game *Game::getInstance()
{
    std::lock_guard<std::mutex> lock(_mutex);
    if (_instance == nullptr)
    {
        _instance = new Game();
    }
    return _instance;
}