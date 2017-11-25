#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
    VideoMode vm(1920, 1080); // instance of VideoMode called vm
    RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

    Sprite spriteBackground;
    Texture textureBackground;
    textureBackground.loadFromFile("graphics/background.png");
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);

    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        window.clear();
        window.draw(spriteBackground);
        window.display();
    }

    return 0;
}