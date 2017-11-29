#include <SFML/Graphics.hpp>
#include <sstream>
#include "Hud.hpp"

using namespace sf;
using namespace std;

Hud::Hud(GameState* gameState, sf::Text scoreText) {
    this->gameState = gameState;
    this->scoreText = scoreText;
}

Hud Hud::create(GameState* gameState) {
    /* font must be a pointer so that scoreText
     * can reference it without it being destroyed.
     */
    Font* font = new Font();
    Text scoreText;

    font->loadFromFile("fonts/KOMIKAP_.ttf");
    scoreText.setFont(*font);
    scoreText.setCharacterSize(70);
    scoreText.setColor(Color::White);
    scoreText.setPosition(20, 20);

    return Hud(gameState, scoreText);
}

void Hud::next() {
    std::stringstream scoreStream;
    scoreStream << "Score: " << this->gameState->getScore();
    scoreText.setString(scoreStream.str());
}

sf::Text Hud::getScoreText() {
    return this->scoreText;
}
