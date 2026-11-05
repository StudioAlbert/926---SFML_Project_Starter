
#include <ostream>
#include <print>

#include <SFML/Graphics/RenderTarget.hpp>

#include "../include/constants.hpp"
#include "../include/entity.hpp"

void Entity::Setup(sf::Color color, sf::Vector2f size) {
    shape.setFillColor(color);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(1);
    shape.setSize(size);
    shape.setOrigin({size.x / 2, size.y / 2});
}

void Entity::SetupPhysics(b2WorldId &world, b2BodyType type, b2Vec2 position) {

    b2Vec2 halfSize = {Conversions::ScreenToPhysics(shape.getSize().x / 2), Conversions::ScreenToPhysics(shape.getSize().y / 2)};

    physics.Setup(
        world,
        type,
        position,
        halfSize
    );
}

void Entity::Update() {

    //physics.Update();

    sf::Vector2f newPosition;
    newPosition.x = Conversions::PhysicsToScreen(physics.GetPosition().x);
    newPosition.y = Conversions::PhysicsToScreen(physics.GetPosition().y);

    shape.setPosition(newPosition);
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(shape, states);
}

void Entity::MoveLeft() {
    std::println("Move Left");
    float yVelocity = physics.GetVelocity().y;
    physics.SetVelocity({-X_VELOCITY, yVelocity});
}
void Entity::MoveRight() {
    std::println("Move Right");
    float yVelocity = physics.GetVelocity().y;
    physics.SetVelocity({X_VELOCITY, yVelocity});
}
void Entity::Jump() {
    std::println("Jump");
}

void Entity::CancelMovement() {
    float yVelocity = physics.GetVelocity().y;
    physics.SetVelocity({0, yVelocity});
}
