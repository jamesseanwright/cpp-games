#pragma once

#include<unordered_map>
#include "../components/Component.hpp"

using namespace std;

class Entity {
    private:
        unordered_map<string, Component> components;
        Entity(unordered_map<string, Component> components);

    public:
        static Entity create(Component components []);
};

#pragma once