#include <SFML/Graphics.hpp>
#include "Keys.hpp"

using namespace sf;

Keys::Keys() {
    this->clock = Clock();
}

Keys Keys::create() {
    return Keys();
}

bool Keys::isReleasedWithThrottle(Event* event, Keyboard::Key key) {
    if (event->type != Event::KeyReleased) {
        return false;
    }

    this->lastKey = key; // TODO: restart clock if changed

    Time elapsedTime = this->clock.getElapsedTime();
    bool isReleased = elapsedTime.asMilliseconds() > Keys::THROTTLE_MS && event->key.code == key;

    if (isReleased) {
        this->clock.restart();
    }

    return isReleased;
}
