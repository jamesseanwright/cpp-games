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

DecorativeSprite::DecorativeSprite(Texture& texture, Vector2u screenRes) {
    this->sprite = Sprite(texture);
    this->screenRes = screenRes;
    this->isActive = false;
    this->xSpeed = 0.0f;
}

void DecorativeSprite::initialise() {
    unsigned int screenMidY = screenRes.y / 2;

    srand((int)time(0));
    this->xSpeed = (rand() % 200 + 200);

    srand((int)time(0) * 10);
    this->sprite.setPosition(this->screenRes.x, rand() % screenMidY);
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
            position.x - this->xSpeed * deltaSecs,
            position.y
        );
    }
}

Sprite DecorativeSprite::getSprite() {
    return this->sprite;
}

DecorativeSprite DecorativeSprite::createBee(Vector2u screenRes) {
    return DecorativeSprite(DecorativeSprite::beeTexture, screenRes);
}

DecorativeSprite DecorativeSprite::createCloud(Vector2u screenRes) {
    return DecorativeSprite(DecorativeSprite::cloudTexture, screenRes);
}