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

DecorativeSprite::DecorativeSprite(Texture& texture, Vector2u screenRes, Direction direction, int xSpeed, float initialYPos) {
    this->sprite = Sprite(texture);
    this->screenRes = screenRes;
    this->direction = direction;
    this->isActive = false;
    this->xSpeed = xSpeed;
    this->initialXPos = direction == Direction::left ? screenRes.x : 0;
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

    Vector2f position = this->sprite.getPosition();

    if (position.x < -100) {
        this->isActive = false;
    } else {
        this->sprite.setPosition(
            position.x + (this->xSpeed * deltaSecs) * this->direction,
            position.y
        );
    }
}

Sprite DecorativeSprite::getSprite() {
    return this->sprite;
}

DecorativeSprite DecorativeSprite::createBee(Vector2u screenRes) {
    return DecorativeSprite(DecorativeSprite::beeTexture, screenRes, Direction::left, 200, screenRes.y / 2);
}

DecorativeSprite DecorativeSprite::createCloud(Vector2u screenRes, int xSpeed, float initialYPos) {
    return DecorativeSprite(DecorativeSprite::cloudTexture, screenRes, Direction::right, xSpeed, initialYPos);
}