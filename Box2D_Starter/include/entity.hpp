//
// Created by sebas on 04.11.2026.
//

#ifndef SFML_PROJECT_MASTER_ENTITY_HPP
#define SFML_PROJECT_MASTER_ENTITY_HPP
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "physical_object.hpp"

class Entity : public sf::Drawable {

    sf::RectangleShape shape;
    sf::Texture texture;
    PhysicalObject physics;

    public:
    void Setup(sf::Color color, sf::Vector2f size);
    void SetupPhysics(b2WorldId &world, b2BodyType type, b2Vec2 position);
    void Update();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};

#endif //SFML_PROJECT_MASTER_ENTITY_HPP
