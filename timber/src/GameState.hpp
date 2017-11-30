#pragma once

class GameState {
    private:
        const int SCORE_INCREMENT = 10;
        const float TOTAL_TIME_SECS = 5;

        GameState();
        bool paused;
        int score;
        float timeRemainingSecs;

    public:
        static GameState create();
        void togglePause();
        bool isPaused();
        void incrementScore();
        int getScore();
        void decrementTimeRemaining(float deltaSecs);
        float getTimeRemainingSecs();
};

#pragma once