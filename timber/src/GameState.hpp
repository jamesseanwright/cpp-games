#pragma once

class GameState {
    private:
        GameState();
        bool paused;

    public:
        static GameState create();
        void togglePause();
        bool isPaused();
};

#pragma once