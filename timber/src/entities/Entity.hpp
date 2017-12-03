#pragma once

#include <unordered_map>
#include <vector>
#include "../components/Component.hpp"

using namespace std; // TODO: remove namespaces

class Entity {
    private:
        unordered_map<string, Component*> components;

    public:
        Entity(vector<Component>* components);
};

#pragma once