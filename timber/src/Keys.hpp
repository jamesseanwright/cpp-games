#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Keys {
    const Int32 THROTTLE_MS = 200;

    private:
        Keys();
        Clock clock;
        Keyboard::Key lastKey;

    public:
        bool isReleasedWithThrottle(Event* event, Keyboard::Key key);
        static Keys create();
};

#pragma once
