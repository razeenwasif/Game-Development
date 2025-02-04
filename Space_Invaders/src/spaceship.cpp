#include "headers/spaceship.hpp"

Spaceship::Spaceship() {
    image = LoadTexture("assets/spaceship.png");
    position.x = (GetScreenWidth() - image.width) / 2;
    position.y = GetScreenHeight() - image.height - 100;
    delayLaser = 0.0;
    laserSound = LoadSound("assets/laser.ogg");
}

// unload the image upon game closing
Spaceship::~Spaceship() {
    UnloadTexture(image);
    UnloadSound(laserSound);
}

void Spaceship::draw() {
    DrawTextureV(image, position, WHITE);
}

void Spaceship::moveLeft() {
    int OFFSET = 25;
    position.x -= velocity;
    if (position.x < OFFSET) {
        position.x = OFFSET;
    }
}

void Spaceship::moveRight() {
    int OFFSET = 25;
    position.x += velocity;
    if (position.x > GetScreenWidth() - image.width - OFFSET) {
        position.x = GetScreenWidth() - image.width - OFFSET;
    }
}

void Spaceship::fireLaser() {
    if (GetTime() - delayLaser >= 0.35)
    lasers.push_back(Laser({position.x + image.width / 2 - 2, position.y}, -laserSpeed));
    PlaySound(laserSound);
    delayLaser = GetTime(); 
}

Rectangle Spaceship::getRect()
{
    return {position.x, position.y, float(image.width), float(image.height)};
}

void Spaceship::reset()
{
    position.x = (GetScreenWidth() - image.width) / 2.0f;
    position.y = GetScreenHeight() - image.height - 100;
    lasers.clear();
}
