#include <SFML/Graphics.hpp>
#include "DecorativeSprite.hpp"

using namespace sf;

int main() {
    VideoMode vm(1920, 1080); // instance of VideoMode called vm
    RenderWindow window(vm, "Timber!!!", Style::Titlebar);

    DecorativeSprite bee = DecorativeSprite::createBee(window.getSize());

    DecorativeSprite clouds [3] = {
        DecorativeSprite::createCloud(window.getSize()),
        DecorativeSprite::createCloud(window.getSize()),
        DecorativeSprite::createCloud(window.getSize())
    };

    Sprite spriteBackground;
    Sprite spriteTree;

    Texture textureBackground;
    Texture textureTree;

    textureBackground.loadFromFile("graphics/background.png");
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);

    textureTree.loadFromFile("graphics/tree.png");
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);

    Clock clock;

    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        Time deltaTime = clock.restart();
        float deltaSeconds = deltaTime.asSeconds();

        bee.next(deltaSeconds);

        // for (DecorativeSprite cloud : clouds) {
            clouds[0].next(deltaSeconds);
        // }

        window.clear();
        window.draw(spriteBackground);

        // for (DecorativeSprite cloud : clouds) {
            window.draw(clouds[0].getSprite());

            // window.draw(cloud.getSprite());
        // }

        window.draw(spriteTree);
        window.draw(bee.getSprite());

        window.display();
    }

    return 0;
}