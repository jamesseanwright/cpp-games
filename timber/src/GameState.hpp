#pragma once

enum StateFlag {
    title,
    gameStarted,
    outOfTime
};

class GameState {
    private:
        constexpr static int SCORE_INCREMENT = 10;
        GameState();
        bool paused;
        int score;
        float timeRemainingSecs;
        StateFlag stateFlag;
        void init();

    public:
        constexpr static float TOTAL_TIME_SECS = 5;
        static GameState create();
        void togglePause();
        bool isPaused();
        void incrementScore();
        int getScore();
        void decrementTimeRemaining(float deltaSecs);
        float getTimeRemainingSecs();
        StateFlag getStateFlag();
};

#pragma once