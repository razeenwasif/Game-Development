#pragma once
#include <raylib.h>

class Laser {
    public:
        Laser(Vector2 position, int speed);
        void update();
        void draw();
        Rectangle getRect();
        bool active;

    private:
        Vector2 position;
        int speed;
};