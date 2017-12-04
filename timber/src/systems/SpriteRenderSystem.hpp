#pragma once

#include <SFML/Graphics.hpp>
#include "System.hpp"

class SpriteRenderSystem : System {
    private:
        SpriteRenderSystem(sf::RenderWindow* window);
        sf::RenderWindow* window;
        void next(Entity* entity, float deltaSecs);

    public:
        static SpriteRenderSystem create(sf::RenderWindow* window);
};

#pragma once