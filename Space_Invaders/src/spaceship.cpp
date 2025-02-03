#include "spaceship.hpp"

Spaceship::Spaceship() {
    image = LoadTexture("assets/spaceship.png");
    position.x = (GetScreenWidth() - image.width) / 2;
    position.y = GetScreenHeight() - image.height - 8;
    delayLaser = 0.0;
}

// unload the image upon game closing
Spaceship::~Spaceship() {
    UnloadTexture(image);
}

void Spaceship::draw() {
    DrawTextureV(image, position, WHITE);
}

void Spaceship::moveLeft() {
    position.x -= velocity;
    if (position.x < 0) {
        position.x = 0;
    }
}

void Spaceship::moveRight() {
    position.x += velocity;
    if (position.x > GetScreenWidth() - image.width) {
        position.x = GetScreenWidth() - image.width;
    }
}

void Spaceship::fireLaser() {
    if (GetTime() - delayLaser >= 0.35)
    lasers.push_back(Laser({position.x + image.width / 2 - 2, position.y}, -laserSpeed));
    delayLaser = GetTime();
}
