#pragma once

#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "Component.hpp"

class SpriteRenderable : Component {
    private:
        SpriteRenderable(sf::Sprite* sprite);
        sf::Sprite* sprite;
        static std::unordered_map<string, sf::Texture> textureCache;

    public:
        static SpriteRenderable create(std::string texturePath); // TODO: make all comps use factories
        sf::Sprite getSprite();
};

#pragma once