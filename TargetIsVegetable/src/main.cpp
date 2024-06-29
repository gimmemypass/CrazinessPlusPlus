#include <iostream>
#include "Game.h"
int main()
{
    auto game = Game();
    game.Initialize();
    game.Run();

    return 0;
}