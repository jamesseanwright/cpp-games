#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

enum Direction {
    left = -1,
    right = 1
};

class DecorativeSprite {
    private:
        DecorativeSprite(Texture& texture, Vector2u screenRes, Direction direction);
        void initialise();
        Sprite sprite;
        Vector2u screenRes;
        Direction direction;
        float xSpeed;
        float initialXPos;
        bool isActive;
        static Texture beeTexture;
        static Texture cloudTexture;

    public:
        void next(float deltaSecs);
        Sprite getSprite();
        static DecorativeSprite createBee(Vector2u screenRes);
        static DecorativeSprite createCloud(Vector2u screenRes);
};

#pragma once