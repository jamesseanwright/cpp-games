#include <SFML/Graphics.hpp>
#include "DecorativeSprite.hpp"
#include "GameState.hpp"
#include "Hud.hpp"
#include "Keys.hpp"

using namespace sf;

int main() {
    GameState gameState = GameState::create();
    VideoMode vm(1920, 1080); // instance of VideoMode called vm
    RenderWindow window(vm, "Timber!!!", Style::Titlebar);

    Keys keys = Keys::create();
    Hud hud = Hud::create(&gameState, &window);
    DecorativeSprite bee = DecorativeSprite::createBee(&window);

    DecorativeSprite clouds [3] = {
        DecorativeSprite::createCloud(&window, 20, 10),
        DecorativeSprite::createCloud(&window, 40, 80),
        DecorativeSprite::createCloud(&window, 70, 160)
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
    Event event;

    while (window.isOpen()) {
        if (keys.isPressedWithThrottle(Keyboard::Escape)) {
            window.close();
        }

        if (keys.isPressedWithThrottle(Keyboard::Return)) {
            gameState.togglePause();
        }

        Time deltaTime = clock.restart();

        if (!gameState.isPaused()) {
            float deltaSeconds = deltaTime.asSeconds();

            bee.next(deltaSeconds);

            for (DecorativeSprite& cloud : clouds) {
                cloud.next(deltaSeconds);
            }

            hud.next();
        }

        window.clear();
        window.draw(spriteBackground);

        for (DecorativeSprite& cloud : clouds) {
            cloud.render();
        }

        window.draw(spriteTree);
        bee.render();
        hud.render();

        window.display();
    }

    return 0;
}