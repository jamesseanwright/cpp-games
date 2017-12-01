#include <SFML/Graphics.hpp>
#include "DecorativeSprite.hpp"

using namespace std;

Texture DecorativeSprite::beeTexture = [] { // lambda initialiser!
    Texture texture;
    texture.loadFromFile("graphics/bee.png");
    return texture;
}();

Texture DecorativeSprite::cloudTexture = [] {
    Texture texture;
    texture.loadFromFile("graphics/cloud.png");
    return texture;
}();

DecorativeSprite::DecorativeSprite(Texture& texture, RenderWindow* window, Direction direction, int xSpeed, float initialYPos) {
    this->sprite = Sprite(texture);
    this->window = window;
    this->direction = direction;
    this->isActive = false;
    this->xSpeed = xSpeed;
    this->initialXPos = direction == Direction::left ? window->getSize().x : 0 - sprite.getLocalBounds().width;
    this->initialYPos = initialYPos;
}

void DecorativeSprite::initialise() {
    this->sprite.setPosition(this->initialXPos, this->initialYPos);
}

void DecorativeSprite::next(float deltaSecs) {
    if (!this->isActive) {
        this->initialise();
        this->isActive = true;
    }

    FloatRect bounds = this->sprite.getLocalBounds();
    Vector2f position = this->sprite.getPosition();
    Vector2u windowSize = this->window->getSize();

    if ((this->direction == Direction::left && position.x < 0 - bounds.width) || (this->direction == Direction::right && position.x > windowSize.x)) {
        this->isActive = false;
    } else {
        this->sprite.setPosition(
            position.x + (this->xSpeed * deltaSecs) * (int)this->direction,
            position.y
        );
    }
}

void DecorativeSprite::render() {
    this->window->draw(this->sprite);
}

DecorativeSprite DecorativeSprite::createBee(RenderWindow* window) {
    return DecorativeSprite(DecorativeSprite::beeTexture, window, Direction::left, 200, window->getSize().y / 2);
}

DecorativeSprite DecorativeSprite::createCloud(RenderWindow* window, int xSpeed, float initialYPos) {
    return DecorativeSprite(DecorativeSprite::cloudTexture, window, Direction::right, xSpeed, initialYPos);
}