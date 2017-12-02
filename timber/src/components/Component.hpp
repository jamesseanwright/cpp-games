#pragma once

#include <SFML/Graphics.hpp>
#include "../systems/System.hpp";

using namespace sf;
using namespace std;

class Component {
    private:
        Component(System* system, string name);
        System* system;
        string name;
        void next(Entity* entity, float deltaSeconds);

    public:
        string getName();
        static Component create(System* system, string name);
};

#pragma once
