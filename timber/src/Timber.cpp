#include <SFML/Graphics.hpp>
#include "DecorativeSprite.hpp"
#include "GameState.hpp"

using namespace sf;

int main() {
    GameState gameState = GameState::create();
    VideoMode vm(1920, 1080); // instance of VideoMode called vm
    RenderWindow window(vm, "Timber!!!", Style::Titlebar);

    DecorativeSprite bee = DecorativeSprite::createBee(window.getSize());

    DecorativeSprite clouds [3] = {
        DecorativeSprite::createCloud(window.getSize(), 20, 10),
        DecorativeSprite::createCloud(window.getSize(), 40, 80),
        DecorativeSprite::createCloud(window.getSize(), 70, 160)
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

        if (Keyboard::isKeyPressed(Keyboard::Return)) {
            gameState.unpause();
        }

        if (!gameState.isPaused()) {
            Time deltaTime = clock.restart();
            float deltaSeconds = deltaTime.asSeconds();

            bee.next(deltaSeconds);

            for (DecorativeSprite& cloud : clouds) {
                cloud.next(deltaSeconds);
            }
        }

        window.clear();
        window.draw(spriteBackground);

        for (DecorativeSprite& cloud : clouds) {
            window.draw(cloud.getSprite());
        }

        window.draw(spriteTree);
        window.draw(bee.getSprite());

        window.display();
    }

    return 0;
}