#include <SFML/Graphics.hpp>
#include "DecorativeSprite.hpp"

using namespace sf;

int main() {
    VideoMode vm(1920, 1080); // instance of VideoMode called vm
    RenderWindow window(vm, "Timber!!!", Style::Titlebar);

    DecorativeSprite bee = DecorativeSprite::createBee(window.getSize());

    Sprite spriteBackground;
    Sprite spriteTree;
    Sprite spriteCloud1;
    Sprite spriteCloud2;
    Sprite spriteCloud3;

    Texture textureBackground;
    Texture textureTree;
    Texture textureCloud;

    textureBackground.loadFromFile("graphics/background.png");
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);

    textureTree.loadFromFile("graphics/tree.png");
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);

    textureCloud.loadFromFile("graphics/cloud.png");
    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);

    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;

    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

    Clock clock;

    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        Time deltaTime = clock.restart();

        bee.next(deltaTime.asSeconds());

        if (!cloud1Active) {
            srand((int)time(0) * 10);
            cloud1Speed = (rand() % 200);

            srand((int)time(0) * 10);
            float y = (rand() % 150);
            spriteCloud1.setPosition(-200, y);
            cloud1Active = true;
        } else {
            spriteCloud1.setPosition(
                spriteCloud1.getPosition().x + cloud1Speed * deltaTime.asSeconds(),
                spriteCloud1.getPosition().y
            );

            if (spriteCloud1.getPosition().x > 1920) {
                cloud1Active = false;
            }
        }

        window.clear();

        window.draw(spriteBackground);
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);
        window.draw(spriteTree);
        window.draw(bee.getSprite());

        window.display();
    }

    return 0;
}