#include <iostream>

#include "include/game.hpp"
#include <SFML/Graphics.hpp>

int main() {

    Game game;
    game.Loop();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
