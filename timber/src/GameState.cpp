#include "GameState.hpp"

GameState::GameState() {
    this->paused = true;
    this->score = 0;
    this->timeRemainingSecs = GameState::TOTAL_TIME_SECS;
    this->stateFlag = StateFlag::title;
}

GameState GameState::create() {
    return GameState(); // Without `new` keyword, this is a stack allocation (TODO: confirm this)
}

void GameState::togglePause() {
    this->paused = !this->paused;

    if (!this->paused && this->stateFlag == StateFlag::title) {
        this->stateFlag = StateFlag::gameStarted;
    }
}

bool GameState::isPaused() {
    return this->paused;
}

void GameState::incrementScore() {
    this->score += GameState::SCORE_INCREMENT;
}

int GameState::getScore() {
    return this->score;
}

void GameState::decrementTimeRemaining(float deltaSecs) {
    this->timeRemainingSecs -= deltaSecs;

    if (this->timeRemainingSecs <= 0) {
        this->stateFlag = StateFlag::title;
    }
}

float GameState::getTimeRemainingSecs() {
    return this->timeRemainingSecs;
}

StateFlag GameState::getStateFlag() {
    return this->stateFlag;
}