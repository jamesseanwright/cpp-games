#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.hpp"

using namespace sf;

class Hud {
    private:
        Hud(GameState* gameState, sf::Text scoreText);
        GameState* gameState;
        sf::Text scoreText;

    public:
        void next();
        static Hud create(GameState* gameState);
        sf::Text getScoreText();
};

#pragma once