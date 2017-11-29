#include "GameState.hpp"

GameState::GameState() {
    this->paused = true;
}

GameState GameState::create() {
    return GameState(); // Without `new` keyword, this is a stack allocation
}

void GameState::pause() {
    this->paused = true;
}

void GameState::unpause() {
    this->paused = false;
}

bool GameState::isPaused() {
    return this->paused;
}