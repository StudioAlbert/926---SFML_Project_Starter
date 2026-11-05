//
// Created by sebas on 05.11.2026.
//

#include "../include/sensor.hpp"

#include <box2d/box2d.h>

void sensor::Setup(b2WorldId &world, b2Vec2 position, b2Vec2 halfSize) {
    bodyDef_ = b2DefaultBodyDef();
    bodyDef_.type = b2_staticBody;
    bodyDef_.position = position;
    body_ = b2CreateBody(world, &bodyDef_);

    const b2Polygon pieds = b2MakeBox(halfSize.x, halfSize.y);

    b2ShapeDef def = b2DefaultShapeDef();
    def.isSensor = true; // il détecte, il n'arrête rien
    def.enableSensorEvents = true; // sans ça : aucun événement
    def.userData = &body_;

    b2CreatePolygonShape(body_, &def, &pieds);
}

void sensor::Update() {
    const b2SensorEvents sensors = b2World_GetSensorEvents(world);

    for (int i = 0; i < sensors.beginCount; ++i) {
        const b2ContactBeginTouchEvent &e = sensors.beginEvents[i];

        // Les deux formes portent un `Objet*` : le cast est sur, et chacune
        // sait ce qu'elle a touche grace a l'etiquette de l'autre.
        auto *a = static_cast<Objet *>(b2Shape_GetUserData(e.shapeIdA));
        auto *b = static_cast<Objet *>(b2Shape_GetUserData(e.shapeIdB));

        if (a && b) {
            a->Touche(*b);
            b->Touche(*a);
        }
    }
}
