//
// Created by sebas on 05.11.2026.
//

#ifndef SFML_PROJECT_MASTER_SENSOR_HPP
#define SFML_PROJECT_MASTER_SENSOR_HPP
#include <box2d/id.h>
#include <box2d/math_types.h>
#include <box2d/types.h>


class sensor {
    b2BodyDef bodyDef_;
    b2BodyId body_;

public:
    void Setup(b2WorldId &world, b2Vec2 position, b2Vec2 halfSize);
    void Update();
};


#endif //SFML_PROJECT_MASTER_SENSOR_HPP
