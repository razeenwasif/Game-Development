#include "game.hpp"
#include <iostream>

// increase laserspeed as game progresses

Game::Game() {
    barriers = createBarriers();
}

Game::~Game() {

}

void Game::draw() {
    spaceship.draw();

    for (auto& laser : spaceship.lasers) laser.draw();

    for (auto& barrier : barriers) barrier.draw();
}

void Game::update() {
    for (auto& laser : spaceship.lasers) laser.update();
    deleteInactiveLasers();
}

void Game::handleInput() {
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) { spaceship.moveLeft(); } 
    else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) { spaceship.moveRight(); } 
    else if (IsKeyDown(KEY_SPACE)) { spaceship.fireLaser(); }
}

void Game::deleteInactiveLasers() {
    for (auto it = spaceship.lasers.begin(); it != spaceship.lasers.end();) {
        if (!it -> active) { it = spaceship.lasers.erase(it); } 
        else { ++ it; }
    }
}

std::vector<Barrier> Game::createBarriers() {
    int barrierWidth = Barrier::grid[0].size() * 3;
    float gap = (GetScreenWidth() - (4 * barrierWidth)) / 5;

    // create 4 barrier obstacles
    for (int i = 0; i < 4; i++) {
        float offsetX = (i + 1) * gap + i * barrierWidth;
        barriers.push_back(Barrier({offsetX,float(GetScreenHeight() - 100)}));
    }
    return barriers;
}
