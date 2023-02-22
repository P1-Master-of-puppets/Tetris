#include <iostream>
#include "game.h"
#inlcude "input"


int main()
{
    Game game;

	game.start();

	while (game.getState() == GameState::OnGoing)
	{
		std::cout << "Run" << std::endl;
	}
    return 0;
}