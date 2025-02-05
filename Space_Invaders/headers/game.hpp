#pragma once
#include "spaceship.hpp"
#include "barrier.hpp"
#include "alien.hpp"
#include "mysteryship.hpp"

class Game {
    public:
        Game();
        ~Game();
        void draw();
        void update();
        void updateAI();
        void handleInput();
        int currentMode;
        int lives;
        bool run;
        int score;
        int highscore;
        Music music;

        static const int PLAYER_MODE = 0;
        static const int AI_MODE = 1;
    
    private:
        Spaceship spaceship;
        MysteryShip mysteryship;
        Sound explosionSound;

        std::vector<Barrier> barriers;
        std::vector<Alien> aliens;
        int aliensDirection;
        std::vector<Laser> alienLasers;
        constexpr static float alienLaserDelay = 0.35;
        float timeLastAlienFired;
        float mysteryshipSpawnInterval;
        float timeLastSpawn;

        void deleteInactiveLasers();
        std::vector<Barrier> createBarriers();
        std::vector<Alien> createAliens();
        void moveAliens();
        void moveAliensDown(int distance);
        void alienShootLaser();
        void checkForCollisions();
        void gameOver();
        void reset();
        void initGame();
        void checkForHighScore();
        void saveHighScore(int highscore);
        int loadHighScore();
};