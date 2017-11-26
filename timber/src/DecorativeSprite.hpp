#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class DecorativeSprite {
    private:
        DecorativeSprite(Texture texture, Vector2u screenRes); // TODO friend via new class?
        void initialise();
        Sprite sprite;
        Vector2u screenRes;
        float xSpeed;
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