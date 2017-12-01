#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.hpp"

using namespace sf;
using namespace std;

class Hud {
    private:
        constexpr static float TIMEBAR_WIDTH = 400;
        constexpr static float TIMEBAR_HEIGHT = 80;
        constexpr static float TIMEBAR_SECOND_WIDTH = TIMEBAR_WIDTH / GameState::TOTAL_TIME_SECS;

        Hud(GameState* gameState, RenderWindow* window, Text scoreText, Text pauseText, RectangleShape timeBar);
        GameState* gameState;
        RenderWindow* window;
        Text scoreText;
        Text pauseText;
        RectangleShape timeBar; // could live in its own class, but cba LOL

    public:
        void next(float deltaSecs);
        void render();
        string getPauseText();
        static Hud create(GameState* gameState, RenderWindow* window);
};

#pragma once