//
// Created by sebas on 22.10.2026.
//

#ifndef SFML_PROJECT_MASTER_GAME_HPP
#define SFML_PROJECT_MASTER_GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Game {

    sf::RenderWindow window;

    sf::Texture char_texture_;
    sf::Texture weapon_texture_;
    sf::Texture sprite_sheet_;

    std::optional<sf::Sprite> character;
    std::optional<sf::Sprite> weapon;
    sf::RectangleShape rect;

    sf::SoundBuffer buffer_;
    std::optional<sf::Sound> sound_;

public:
    void Initialize();
    void Loop();

};


#endif //SFML_PROJECT_MASTER_GAME_HPP
