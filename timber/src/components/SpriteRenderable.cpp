#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "Component.hpp"
#include "SpriteRenderable.hpp"

SpriteRenderable::SpriteRenderable(sf::Sprite* sprite) {
    this->sprite = sprite;
}

SpriteRenderable SpriteRenderable::create(std::string texturePath) {
    sf::Texture texture;

    if (SpriteRenderable::textureCache.count(texturePath) > 0) {
        texture = SpriteRenderable::textureCache[texturePath];
    } else {
        texture.loadFromFile(texturePath);
    }

    return SpriteRenderable(&sf::Sprite(texture));
}

sf::Sprite* SpriteRenderable::getSprite() {
    return this->sprite;
}
