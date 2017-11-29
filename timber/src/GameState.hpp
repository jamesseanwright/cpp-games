#pragma once

class GameState {
    private:
        GameState();
        bool paused;

    public:
        static GameState create();
        void pause();
        void unpause();
        bool isPaused();
};

#pragma once