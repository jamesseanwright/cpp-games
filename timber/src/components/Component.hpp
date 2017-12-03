#pragma once

#include <string>
#include "../systems/System.hpp"

using namespace std;

class Component {
    protected:
        System* system;
        string name;

    public:
        string getName();

};

#pragma once
