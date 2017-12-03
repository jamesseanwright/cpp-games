#pragma once

#include "Component.hpp"

using namespace std;

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