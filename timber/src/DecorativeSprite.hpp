#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

enum class Direction : int {
    left = -1,
    right = 1
};

class DecorativeSprite {
    private:
        DecorativeSprite(Texture& texture, RenderWindow* window, Direction direction, int xSpeed, float initialYPos);
        void initialise();
        Sprite sprite;
        RenderWindow* window;
        Direction direction;
        int xSpeed;
        float initialXPos;
        float initialYPos;
        bool isActive;
        static Texture beeTexture;
        static Texture cloudTexture;

    public:
        void next(float deltaSecs);
        void render();
        static DecorativeSprite createBee(RenderWindow* window);
        static DecorativeSprite createCloud(RenderWindow* window, int xSpeed, float initialYPos);
};

#pragma once