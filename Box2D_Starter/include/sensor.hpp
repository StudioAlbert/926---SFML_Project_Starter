//
// Created by sebas on 05.11.2026.
//

#ifndef SFML_PROJECT_MASTER_SENSOR_HPP
#define SFML_PROJECT_MASTER_SENSOR_HPP
#include <box2d/id.h>
#include <box2d/math_types.h>

class sensor {
public:
    void Setup(b2BodyId body_id, b2Vec2 halfSize);
    bool HasTouched = false;
};


#endif //SFML_PROJECT_MASTER_SENSOR_HPP
