//
// Created by sebas on 05.11.2026.
//

#include "../include/sensor.hpp"

#include <box2d/box2d.h>

void sensor::Setup(b2BodyId body_id, b2Vec2 halfSize) {

    const b2Polygon box = b2MakeOffsetBox(halfSize.x, halfSize.y, {0,0}, b2Rot_identity);

    b2ShapeDef def = b2DefaultShapeDef();
    def.isSensor = true; // il détecte, il n'arrête rien
    def.enableSensorEvents = true; // sans ça : aucun événement
    def.userData = this;

    b2CreatePolygonShape(body_id, &def, &box);

}


