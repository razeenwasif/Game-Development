#include "headers/mysteryship.hpp"

MysteryShip::MysteryShip()
{
    image = LoadTexture("assets/mystery.png");
    alive = false;
}

MysteryShip::~MysteryShip()
{
    UnloadTexture(image);
}

void MysteryShip::update()
{
    int OFFSET = 25;
    if (alive) {
        position.x += speed;
        if (position.x > GetScreenWidth() - image.width - OFFSET || position.x < OFFSET) alive = false;
    }
}

void MysteryShip::spawn()
{
    int OFFSET = 25;
    position.y = 90;
    int side = GetRandomValue(0, 1);
    if (side == 0) {
        position.x = OFFSET;
        speed = 3;
    } else {
        position.x = GetScreenWidth() - image.width - OFFSET;
        speed = -3;
    }
    alive = true;
}

Rectangle MysteryShip::getRect()
{
    if (alive) {
        return {position.x, position.y, float(image.width), float(image.height)};
    } else {
        return {position.x, position.y, 0, 0};
    }
}

void MysteryShip::draw()
{
    if (alive) DrawTextureV(image, position, WHITE);
}
