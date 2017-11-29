#include <SFML/Graphics.hpp>
#include "Keys.hpp"

using namespace sf;

Keys::Keys() {
    this->clock = sf::Clock();
}

Keys Keys::create() {
    return Keys();
}

bool Keys::isPressedWithThrottle(Keyboard::Key key) {
    sf::Time elapsedTime = this->clock.getElapsedTime();
    bool isPressed = elapsedTime.asMilliseconds() > Keys::THROTTLE_MS && sf::Keyboard::isKeyPressed(key);

    if (isPressed) {
        this->clock.restart();
    }

    return isPressed;
}
