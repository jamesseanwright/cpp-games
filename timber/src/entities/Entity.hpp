#pragma once

#include <unordered_map>
#include "../components/Component.hpp"

using namespace std; // TODO: remove namespaces

class Entity {
    private:
        unordered_map<string, Component*> components;

    public:
        Entity(Component components []);

        template<typename T>
        T getComponent(string name);
};

#pragma once
