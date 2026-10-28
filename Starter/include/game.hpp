//
// Created by sebas on 22.10.2026.
//

#ifndef SFML_PROJECT_MASTER_GAME_HPP
#define SFML_PROJECT_MASTER_GAME_HPP

#include <SFML/Graphics.hpp>

class Game {

    sf::RenderWindow window;

    std::optional<sf::Sprite> cuphead;
    sf::Texture texture;

public:
    void Initialize();
    void Loop();

};


#endif //SFML_PROJECT_MASTER_GAME_HPP
