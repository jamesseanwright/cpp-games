#include "GameState.hpp"

GameState::GameState() {
    this->paused = true;
}

GameState GameState::create() {
    return GameState(); // Without `new` keyword, this is a stack allocation
}

void GameState::togglePause() {
    this->paused = !this->paused;
}
bool GameState::isPaused() {
    return this->paused;
}