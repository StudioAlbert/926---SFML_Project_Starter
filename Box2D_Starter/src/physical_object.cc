#include "../include/physical_object.hpp"

#include <print>
#include <box2d/box2d.h>

void PhysicalObject::Setup(b2WorldId &world, b2BodyType type, b2Vec2 position, b2Vec2 halfSize) {

    def_ = b2DefaultBodyDef();
    def_.type = type;
    def_.position = position;

    body_ = b2CreateBody(world, &def_);

    // --- la forme, et sa matiere -------------------------------------------
    b2Polygon square = b2MakeBox(halfSize.x, halfSize.y);

    shape_def_ = b2DefaultShapeDef();
    shape_def_.density = 1.0f;
    shape_def_.material.friction = 0.0f;
    shape_def_.material.restitution = 0.0f;
    b2CreatePolygonShape(body_, &shape_def_, &square);

    b2MassData myMassData;
    myMassData.mass = 5.0f;
    myMassData.center = {0.0f, 0.0f};
    myMassData.rotationalInertia = 0.0f;
    b2Body_SetMassData(body_, myMassData);

}

void PhysicalObject::Update() {
    std::println("object position , {} : {}", b2Body_GetPosition(body_).x, b2Body_GetPosition(body_).y);
}

b2Vec2 PhysicalObject::GetPosition() {
    return b2Body_GetPosition(body_);
}
