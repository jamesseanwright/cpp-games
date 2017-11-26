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

DecorativeSprite::DecorativeSprite(Texture texture, Vector2u screenRes) {
    this->sprite = Sprite(texture);
    this->screenRes = screenRes;
}

void DecorativeSprite::next() {
    // TODO: game loop logic
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