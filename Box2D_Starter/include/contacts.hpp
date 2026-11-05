//
// Created by sebas on 05.11.2026.
//

#ifndef SFML_PROJECT_MASTER_CONTACTS_HPP
#define SFML_PROJECT_MASTER_CONTACTS_HPP

#include <print>
#include <box2d/box2d.h>
#include "sensor.hpp"

void SensorsContact(b2WorldId worldId) {

    const b2SensorEvents sensors = b2World_GetSensorEvents(worldId);

    for (int i = 0; i < sensors.beginCount; ++i) {

        const b2SensorBeginTouchEvent &e = sensors.beginEvents[i];

        // Les deux formes portent un `Objet*` : le cast est sur, et chacune
        // sait ce qu'elle a touche grace a l'etiquette de l'autre.
        auto *a = static_cast<sensor*>(b2Shape_GetUserData(e.sensorShapeId));
        auto *b = static_cast<sensor*>(b2Shape_GetUserData(e.visitorShapeId));

        if (a) {
            a->HasTouched = true;
        }
        if (b) {
            b->HasTouched = true;
        }
    }

    for (int i = 0; i < sensors.endCount; ++i) {

        const b2SensorEndTouchEvent &e = sensors.endEvents[i];

        // Les deux formes portent un `Objet*` : le cast est sur, et chacune
        // sait ce qu'elle a touche grace a l'etiquette de l'autre.
        auto *a = static_cast<sensor*>(b2Shape_GetUserData(e.sensorShapeId));
        auto *b = static_cast<sensor*>(b2Shape_GetUserData(e.visitorShapeId));

        if (a) {
            a->HasTouched = false;
        }
        if (b) {
            b->HasTouched = false;
        }
    }

}

#endif //SFML_PROJECT_MASTER_CONTACTS_HPP
