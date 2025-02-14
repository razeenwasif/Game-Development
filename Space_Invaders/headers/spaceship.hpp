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
        Rectangle getRect();
        void reset();
        std::vector<Laser> lasers;
        float laserSpeed = 6.0f;
        Vector2 position;

    private:
        Texture2D image;
        const float velocity = 7.0f;
        double delayLaser;
        Sound laserSound;
};