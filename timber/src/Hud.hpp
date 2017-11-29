#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.hpp"

using namespace sf;

class Hud {
    private:
        Hud(GameState* gameState, RenderWindow* window, sf::Text scoreText, sf::Text pauseText);
        GameState* gameState;
        RenderWindow* window;
        sf::Text scoreText;
        sf::Text pauseText;

    public:
        void next();
        void render();
        static Hud create(GameState* gameState, RenderWindow* window);
};

#pragma once