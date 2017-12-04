#pragma once

#include "Component.hpp"

const std::string POSITIONABLE_NAME = "Positionable";

class Positionable : Component {
    private:
        float x;
        float y;

    public:
        Positionable(float x, float y);
        float getX();
        float getY();
};

#pragma once