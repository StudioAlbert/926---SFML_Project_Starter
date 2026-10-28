#include <print>

#include "include/game.hpp"
#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "The Game", sf::Style::Default);
    window.setFramerateLimit(120);

    // sf::Vector2f size_brackets = {100,100};
    // sf::Vector2f size_ctor(100,100);

    sf::RectangleShape rect({100,100});
    rect.setFillColor(sf::Color::White);
    rect.setPosition({window.getSize().x / 2.f, window.getSize().y / 2.f});
    rect.setOrigin({rect.getSize().x / 2, rect.getSize().y / 2});

    sf::Texture texture("../../Starter/ressources/Cuphead_Run_03.png");
    sf::Sprite cuphead(texture);
    cuphead.setPosition({window.getSize().x / 2.f, window.getSize().y / 2.f});
    cuphead.setOrigin({texture.getSize().x / 2.f, texture.getSize().y / 2.f});

    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            else if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
                if (key->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }
        }

        // Gameplay loop ----------------------------
        //rect.move({10,10});

        window.clear(sf::Color::Black);
        //window.draw(rect);
        window.draw(cuphead);
        window.display();

    }

    std::println("End of the game");
    return 0;

}
