#include "laser.hpp"
#include <iostream>

Laser::Laser(Vector2 position, int speed) {
    this -> position = position;
    this -> speed = speed;
    active = true;
}

void Laser::draw() {
    if (active) DrawRectangle(position.x, position.y, 4, 15, {243, 216, 63, 255});
}

void Laser::update() {
    position.y += speed;

    if (active) {
        // destroy laser once out of frame
        if (position.y > GetScreenHeight() || position.y < 0) {
            active = false;
        }
    }
}