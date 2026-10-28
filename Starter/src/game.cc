//
// Created by sebas on 22.10.2026.
//

#include <print>
#include "../include/game.hpp"

void Game::Initialize() {
    window.create(sf::VideoMode({800, 600}), "The Game", sf::Style::Default);
    window.setFramerateLimit(120);

    sf::RectangleShape rect({100, 100});
    rect.setFillColor(sf::Color::White);
    rect.setPosition({window.getSize().x / 2.f, window.getSize().y / 2.f});
    rect.setOrigin({rect.getSize().x / 2, rect.getSize().y / 2});

    texture.loadFromFile("../../Starter/ressources/Cuphead_Run_03.png");

    cuphead = sf::Sprite(texture);
    if (cuphead) {
        cuphead->setTexture(texture);
        cuphead->setPosition({window.getSize().x / 2.f, window.getSize().y / 2.f});
        cuphead->setOrigin({texture.getSize().x / 2.f, texture.getSize().y / 2.f});
    }
}

void Game::Loop() {
    while (window.isOpen()) {

        float dead_zone = 20.f;
        sf::Vector2f joystick;
        joystick.x = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X);
        joystick.y = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y);

        if (std::abs(joystick.x) > dead_zone || std::abs(joystick.y) > dead_zone) {
            constexpr float speed = 5.f;
            sf::Vector2f velocity = sf::Vector2f(speed * joystick.x / 100, speed * joystick.y / 100);
            cuphead->move(velocity);
        }

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (const auto *key = event->getIf<sf::Event::KeyPressed>()) {
                if (key->scancode == sf::Keyboard::Scancode::Escape) {
                    window.close();
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
        if (cuphead.has_value()) {
            window.draw(cuphead.value());
        }
        window.display();
    }
}
