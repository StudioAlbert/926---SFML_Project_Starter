#include <print>

#include "include/game.hpp"

int main() {

    Game game;
    game.Initialize();
    game.Loop();

    std::println("End of the game");
    return EXIT_SUCCESS;

}
