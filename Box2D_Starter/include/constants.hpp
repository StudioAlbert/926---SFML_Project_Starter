//
// Created by sebas on 04.11.2026.
//

#ifndef SFML_PROJECT_MASTER_CONSTANTS_HPP
#define SFML_PROJECT_MASTER_CONSTANTS_HPP

class Conversions {

    static constexpr float pixelsToMeters = 0.05f;

public:
    static float PhysicsToScreen(float meters) {
        return meters / pixelsToMeters;
    }

    static float ScreenToPhysics(float pixels) {
        return pixels * pixelsToMeters;
    }
};

#endif //SFML_PROJECT_MASTER_CONSTANTS_HPP
