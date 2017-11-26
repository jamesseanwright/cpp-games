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

DecorativeSprite::DecorativeSprite(Texture& texture, Vector2u screenRes, Direction direction) {
    this->sprite = Sprite(texture);
    this->screenRes = screenRes;
    this->direction = direction;
    this->isActive = false;
    this->xSpeed = 0.0f;
    this->initialXPos = direction == Direction::left ? screenRes.x : 0;
}

void DecorativeSprite::initialise() {
    unsigned int screenMidY = screenRes.y / 2;

    srand((int)time(0));
    this->xSpeed = (rand() % 200 + 200);

    srand((int)time(0) * 10);
    this->sprite.setPosition(this->initialXPos, rand() % screenMidY);
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
    return DecorativeSprite(DecorativeSprite::beeTexture, screenRes, Direction::left);
}

DecorativeSprite DecorativeSprite::createCloud(Vector2u screenRes) {
    return DecorativeSprite(DecorativeSprite::cloudTexture, screenRes, Direction::right);
}