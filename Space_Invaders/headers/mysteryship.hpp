#pragma once
#include <raylib.h>

class MysteryShip {
    public:
        MysteryShip();
        ~MysteryShip();
        void update();
        void draw();
        void spawn();
        Rectangle getRect();
        bool alive;
        Vector2 position;

    private:
        Texture2D image;
        int speed;
};