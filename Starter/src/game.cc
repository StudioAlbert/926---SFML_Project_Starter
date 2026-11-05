//
// Created by sebas on 22.10.2026.
//

#include <print>
#include "../include/game.hpp"

void Game::Initialize() {
    window.create(sf::VideoMode({800, 600}), "The Game", sf::Style::Default);
    window.setFramerateLimit(60);
    //window.setVerticalSyncEnabled(true);

    rect.setSize({3 * 96, 3 *96});
    rect.setFillColor(sf::Color::White);
    rect.setPosition({window.getSize().x / 2.f, window.getSize().y / 2.f});
    rect.setOrigin({rect.getSize().x / 2, rect.getSize().y / 2});

    char_texture_.loadFromFile("../../Starter/ressources/kenney_desert-shooter-pack_1.0/PNG/Players/Tiles/tile_0001.png");
    weapon_texture_.loadFromFile("../../Starter/ressources/kenney_desert-shooter-pack_1.0/PNG/Weapons/Tiles/tile_0007.png");
    sprite_sheet_.loadFromFile("../../Starter/ressources/kenney_desert-shooter-pack_1.0/PNG/Players/Tilemap/tilemap_packed.png");
    buffer_.loadFromFile("../../Starter/ressources/kenney_interface-sounds/Audio/drop_001.ogg");

    character = sf::Sprite(char_texture_);
    if (character) {
        character->setTexture(char_texture_);
        character->setPosition({window.getSize().x / 2.f, window.getSize().y / 2.f});
        character->setOrigin({char_texture_.getSize().x / 2.f, char_texture_.getSize().y / 2.f});
    }

    weapon = sf::Sprite(weapon_texture_);
    if (weapon) {
        weapon->setTexture(weapon_texture_);
        weapon->setPosition({window.getSize().x / 2.f, window.getSize().y / 2.f});
        weapon->setOrigin({weapon_texture_.getSize().x / 2.f, weapon_texture_.getSize().y / 2.f});
    }

    rect.setTexture(&sprite_sheet_);
    rect.setTextureRect(sf::IntRect({0, 0}, {24,24}));

    sound_ = sf::Sound(buffer_);

}

void Game::Loop() {

    sf::Clock clock;


    while (window.isOpen()) {


        const float dt = clock.restart().asSeconds();
        //std::println("Delta Time = {}", dt);

        float dead_zone = 20.f;
        sf::Vector2f joystick;
        joystick.x = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X);
        joystick.y = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y);

        if (std::abs(joystick.x) > dead_zone || std::abs(joystick.y) > dead_zone) {
            constexpr float speed = 5.f;
            sf::Vector2f velocity = sf::Vector2f(speed * joystick.x / 100, speed * joystick.y / 100);
            character->move(velocity);
            weapon->move(velocity);
            rect.move(velocity);
        }

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (const auto *key = event->getIf<sf::Event::KeyPressed>()) {

                if (key->scancode == sf::Keyboard::Scancode::Escape) {
                    window.close();
                }

                if (key->scancode == sf::Keyboard::Scancode::Space) {
                    if (sound_->getStatus() == sf::SoundSource::Status::Stopped) {
                        sound_->play();
                    }
                }

            } else if (const auto *joystick_event = event->getIf<sf::Event::JoystickButtonPressed>()) {
                std::println("Joystick Button Pressed {}", joystick_event->button);

            } else if (const auto *joystick_event = event->getIf<sf::Event::JoystickMoved>()) {
                std::println("Joystick Axis Moved {}", static_cast<int>(joystick_event->axis));

            } else if (const auto *mouse_event = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouse_event->button == sf::Mouse::Button::Left) {
                    std::println("Left click !");
                }
            }
        }


        // Gameplay loop ----------------------------
        //rect.move({10,10});

        window.clear(sf::Color::Black);
        //window.draw(rect);
        // if (character.has_value()) {
        //     window.draw(character.value());
        // }
        // if (weapon.has_value()) {
        //     window.draw(weapon.value());
        // }
        window.draw(rect);
        window.display();
    }
}
