#include <SFML/Graphics.hpp>
#include <sstream>
#include "Hud.hpp"

using namespace sf;
using namespace std;

Hud::Hud(GameState* gameState, RenderWindow* window, sf::Text scoreText, sf::Text pauseText) {
    this->gameState = gameState;
    this->window = window;
    this->scoreText = scoreText;
    this->pauseText = pauseText;
}

Hud Hud::create(GameState* gameState, RenderWindow* window) {
    /* font must be a pointer so that it
     * has an explicit address when consumed
     * by scoreText (?)
     */
    Font* font = new Font();
    Text scoreText;
    Text pauseText;
    Vector2u windowBounds = window->getSize();

    font->loadFromFile("fonts/KOMIKAP_.ttf");

    scoreText.setFont(*font);
    scoreText.setCharacterSize(70);
    scoreText.setColor(Color::White);
    scoreText.setPosition(20, 20);

    pauseText.setFont(*font);
    pauseText.setCharacterSize(50);
    pauseText.setColor(Color::White);
    pauseText.setPosition(windowBounds.x / 2.0f, windowBounds.y / 2.0f);
    pauseText.setString("Hit Enter to Resume");

    return Hud(gameState, window, scoreText, pauseText);
}

void Hud::next() {
    gameState->incrementScore(); // TODO: temporary - remove!
    std::stringstream scoreStream;
    scoreStream << "Score: " << this->gameState->getScore();
    this->scoreText.setString(scoreStream.str());
}

void Hud::render() {
    this->window->draw(this->scoreText);

    if (this->gameState->isPaused()) {
        FloatRect pauseBounds = this->pauseText.getLocalBounds();

        this->pauseText.setOrigin( // only works once text has been drawn. TODO: initial render bool
            pauseBounds.left + pauseBounds.width / 2.0f,
            pauseBounds.top + pauseBounds.height / 2.0f
        );

        this->window->draw(this->pauseText);
    }
}