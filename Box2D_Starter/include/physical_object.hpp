#ifndef SFML_PROJECT_MASTER_OBJECT_HPP
#define SFML_PROJECT_MASTER_OBJECT_HPP
#include <box2d/types.h>

class PhysicalObject {
    b2BodyDef def_;
    b2BodyId body_;
    b2ShapeDef shape_def_;

public:
    void Setup(b2WorldId &world, b2BodyType type, b2Vec2 position, b2Vec2 halfSize);
    void Update();
    b2Vec2 GetPosition();

    void SetVelocity(b2Vec2 vel);
    b2Vec2 GetVelocity();

    b2BodyId GetBodyId();

};


#endif //SFML_PROJECT_MASTER_OBJECT_HPP
