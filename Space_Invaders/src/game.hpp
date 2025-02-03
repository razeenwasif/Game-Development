#pragma once
#include "spaceship.hpp"
#include "barrier.hpp"

class Game {
    public:
        Game();
        ~Game();
        void draw();
        void update();
        void handleInput();
    
    private:
        Spaceship spaceship;
        std::vector<Barrier> barriers;

        void deleteInactiveLasers();
        std::vector<Barrier> createBarriers();
};