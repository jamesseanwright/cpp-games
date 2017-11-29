#pragma once
#include <SFML/Graphics.hpp>

class Keys {
    const sf::Int32 THROTTLE_MS = 200;

    private:
        Keys();
        sf::Clock clock;

    public:
        bool isPressedWithThrottle(sf::Keyboard::Key key);
        static Keys create();
};

#pragma once
