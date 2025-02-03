#pragma once
#include <raylib.h>
#include "laser.hpp"
#include <vector>

class Spaceship {
    public:
        Spaceship();
        ~Spaceship();
        void draw();
        void moveLeft();
        void moveRight();
        void fireLaser();
        std::vector<Laser> lasers;
        float laserSpeed = 6.0f;

    private:
        Texture2D image;
        Vector2 position;
        const float velocity = 7.0f;
        double delayLaser;
};