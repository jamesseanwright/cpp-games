#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
    VideoMode vm(1920, 1080); // instance of VideoMode called vm
    RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

    Sprite spriteBackground;
    Sprite spriteTree;
    Sprite spriteBee;
    Sprite spriteCloud1;
    Sprite spriteCloud2;
    Sprite spriteCloud3;

    Texture textureBackground;
    Texture textureTree;
    Texture textureBee;
    Texture textureCloud;

    textureBackground.loadFromFile("graphics/background.png");
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);

    textureTree.loadFromFile("graphics/tree.png");
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);

    textureBee.loadFromFile("graphics/bee.png");
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0, 800);

    textureCloud.loadFromFile("graphics/cloud.png");
    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);

    bool beeActive = false;
    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;

    float beeSpeed = 0.0f;
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

    Clock clock;

    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        Time deltaTime = clock.restart();

        if (!beeActive) {
            srand((int) time(0));
            beeSpeed = (rand() % 200) + 200;

            srand((int) time(0) * 10);
            float y = (rand() % 500) + 500;
            spriteBee.setPosition(2000, y);
            beeActive = true;
        } else {
            spriteBee.setPosition(
                spriteBee.getPosition().x - (beeSpeed * deltaTime.asSeconds()),
                spriteBee.getPosition().y
            );

            if (spriteBee.getPosition().x < -100) {
                beeActive = false;
            }
        }

        window.clear();

        window.draw(spriteBackground);
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);
        window.draw(spriteTree);
        window.draw(spriteBee);

        window.display();
    }

    return 0;
}