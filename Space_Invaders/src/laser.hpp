#pragma once
#include <raylib.h>

class Laser {
    public:
        Laser(Vector2 position, int speed);
        void update();
        void draw();
        bool active;

    private:
        Vector2 position;
        int speed;
};