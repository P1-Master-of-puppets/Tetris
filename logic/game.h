#ifndef GAME_H__
#define GAME_H__

#include "piece.h"
#include <mutex>

class Game
{
private:
    static Game *_instance;
    static std::mutex _mutex;

protected:
    Game();
    ~Game();

public:
    // Do not let let clone this class
    Game(Game &game) = delete;

    // Do not let assign
    void operator=(const Game &) = delete;

    static Game *getInstance();
};

#endif // GAME_H__
