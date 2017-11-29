#pragma once

class GameState {
    private:
        const int SCORE_INCREMENT = 10;

        GameState();
        bool paused;
        int score;

    public:
        static GameState create();
        void togglePause();
        bool isPaused();
        void incrementScore();
        int getScore();
};

#pragma once