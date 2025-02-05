#include "headers/game.hpp"
#include <iostream>
#include <fstream>

// increase laserspeed as game progresses

Game::Game() {
    music = LoadMusicStream("assets/music.ogg");
    explosionSound = LoadSound("assets/explosion.ogg");
    PlayMusicStream(music);
    currentMode = PLAYER_MODE; // Initialize to player mode
    initGame();
}

Game::~Game() {
    Alien::unloadImages();
    UnloadMusicStream(music);
    UnloadSound(explosionSound);
}

void Game::update() {
    if (run) {
        if (currentMode == PLAYER_MODE) {
            double currentTime = GetTime();
            if (currentTime - timeLastSpawn > mysteryshipSpawnInterval) {
                mysteryship.spawn();
                timeLastSpawn = GetTime();
                mysteryshipSpawnInterval = GetRandomValue(10, 20);
            }

            for (auto& laser : spaceship.lasers) laser.update();

            moveAliens();

            alienShootLaser();

            for (auto& laser : alienLasers) { laser.update(); }

            deleteInactiveLasers();

            mysteryship.update();

            checkForCollisions();
        } else if (currentMode == AI_MODE) {
            updateAI();
        }
    } else {
        if (IsKeyDown(KEY_ENTER)) {
            reset();
            initGame();
        }
    }
}

void Game::updateAI() {
    if (run) {
        // Implement AI logic here
        // Example: Move spaceship randomly and fire lasers
        if (GetRandomValue(0, 100) < 10) spaceship.moveLeft();
        if (GetRandomValue(0, 100) < 10) spaceship.moveRight();
        if (GetRandomValue(0, 100) < 10) spaceship.fireLaser();

        // Update game elements
        for (auto& laser : spaceship.lasers) laser.update();
        moveAliens();
        alienShootLaser();
        for (auto& laser : alienLasers) laser.update();
        deleteInactiveLasers();
        mysteryship.update();
        checkForCollisions();

        if (aliens.empty()) { gameOver(); }
    }
}

void Game::draw() {
    spaceship.draw();

    for (auto& laser : spaceship.lasers) laser.draw();

    for (auto& barrier : barriers) barrier.draw();

    for (auto& alien : aliens) alien.draw();

    for (auto& laser : alienLasers) { laser.draw(); }

    mysteryship.draw();
}

void Game::handleInput() {
    if (IsKeyPressed(KEY_I)) {
        currentMode = (currentMode == PLAYER_MODE) ? AI_MODE : PLAYER_MODE;
        reset();
        initGame();
    }
    if (run && currentMode == PLAYER_MODE) {
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) { spaceship.moveLeft(); } 
        else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) { spaceship.moveRight(); } 
        else if (IsKeyDown(KEY_SPACE)) { spaceship.fireLaser(); }
    }
}

void Game::deleteInactiveLasers() {
    for (auto it = spaceship.lasers.begin(); it != spaceship.lasers.end();) {
        if (!it -> active) { it = spaceship.lasers.erase(it); } 
        else { ++ it; }
    }
    for (auto it = alienLasers.begin(); it != alienLasers.end();) {
        if (!it -> active) { it = alienLasers.erase(it); } 
        else { ++ it; }
    }
}

std::vector<Barrier> Game::createBarriers() {
    int barrierWidth = Barrier::grid[0].size() * 3;
    float gap = (GetScreenWidth() - (4 * barrierWidth)) / 5;

    // create 4 barrier obstacles
    for (int i = 0; i < 4; i++) {
        float offsetX = (i + 1) * gap + i * barrierWidth;
        barriers.push_back(Barrier({offsetX,float(GetScreenHeight() - 200)}));
    }
    return barriers;
}

std::vector<Alien> Game::createAliens()
{
    std::vector<Alien> aliens; // 5 row x 11 col of aliens
    int cellSize = 55;
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 11; col++) {

            int alienType;
            if (row == 0) { alienType = 3; }
            else if (row == 1 || row == 2) { alienType = 2; }
            else { alienType = 1; }

            float x = 75 + col * cellSize;
            float y = 110 + row * cellSize;
            aliens.push_back(Alien(alienType, {x, y}));
        }
    }
    return aliens;
}

void Game::moveAliens()
{
    int OFFSET = 25;
    for (auto& alien : aliens) {
        if (alien.position.x + alien.alienImages[alien.type - 1].width > GetScreenWidth() - OFFSET) {
            aliensDirection = -1;
            moveAliensDown(2); // Reduced from 4 to 2
        } 
        if (alien.position.x < OFFSET) {
            aliensDirection = 1;
            moveAliensDown(2); // Reduced from 4 to 2
        }
        alien.update(aliensDirection);
    }
}

void Game::moveAliensDown(int distance)
{
    for (auto& alien : aliens) {
        alien.position.y += distance;
    }
}

void Game::alienShootLaser()
{
    double currentTime = GetTime();
    if (currentTime - timeLastAlienFired >= alienLaserDelay && !aliens.empty()) {
        int randIdx = GetRandomValue(0, aliens.size() - 1);
        int laserSpeed = 6;
        Alien& alien = aliens[randIdx];
        alienLasers.push_back(Laser({
            alien.position.x + alien.alienImages[alien.type - 1].width / 2,
            alien.position.y + alien.alienImages[alien.type - 1].height
        }, laserSpeed));
        timeLastAlienFired = GetTime();
    }
}

void Game::checkForCollisions()
{
    // spaceship lasers
    for (auto& laser : spaceship.lasers) {
        auto it = aliens.begin();
        while(it != aliens.end()) {
            if (CheckCollisionRecs(it -> getRect(), laser.getRect())) {
                PlaySound(explosionSound);
                switch(it -> type) {
                    case 1:
                        score += 100;
                        break;
                    case 2:
                        score += 200;
                        break;
                    case 3:
                        score += 300;
                        break;
                    default:
                        score += 0;
                }
                checkForHighScore();
                it = aliens.erase(it);
                laser.active = false;
            } else {
                ++it;
            }
        }

        for (auto& barrier : barriers) {
            auto it = barrier.blocks.begin();
            while(it != barrier.blocks.end()) {
                if (CheckCollisionRecs(it -> getRect(), laser.getRect())) {
                    it = barrier.blocks.erase(it);
                    laser.active = false;
                } else {
                    ++it;
                }
            }
        }

        if (CheckCollisionRecs(mysteryship.getRect(), laser.getRect())) {
            mysteryship.alive = false; laser.active = false; score += 500;
            PlaySound(explosionSound);
            checkForHighScore();
        }
    }

    // alien lasers
    for (auto& laser : alienLasers) {
        if (CheckCollisionRecs(laser.getRect(), spaceship.getRect())) {
            laser.active = false;
            lives --;
            if (lives == 0) { gameOver(); }
        }
        for (auto& barrier : barriers) {
            auto it = barrier.blocks.begin();
            while(it != barrier.blocks.end()) {
                if (CheckCollisionRecs(it -> getRect(), laser.getRect())) {
                    it = barrier.blocks.erase(it);
                    laser.active = false;
                } else {
                    ++it;
                }
            }
        }
    }

    // alien collision with barrier
    for (auto& alien : aliens) {
        for(auto& barrier : barriers) {
            auto it = barrier.blocks.begin();
            while (it != barrier.blocks.end()) {
                if (CheckCollisionRecs(it -> getRect(), alien.getRect())) {
                    it = barrier.blocks.erase(it);
                } else {
                    ++it;
                }
            }
        }
        if (CheckCollisionRecs(alien.getRect(), spaceship.getRect())) {
            gameOver();
        }
    }
}

void Game::gameOver()
{
    run = false;
}

void Game::reset()
{
    spaceship.reset();
    aliens.clear();
    alienLasers.clear();
    barriers.clear();
}

void Game::initGame()
{
    barriers = createBarriers();
    aliens = createAliens();
    aliensDirection = 1;
    timeLastAlienFired = 0;
    timeLastSpawn = 0.0;
    mysteryshipSpawnInterval = GetRandomValue(10, 20);
    lives = 3;
    score = 0;
    highscore = loadHighScore();
    run = true;
}

void Game::checkForHighScore()
{
    if (score > highscore) {highscore = score; saveHighScore(highscore);}
}

void Game::saveHighScore(int highscore)
{
    std::ofstream highscoreFile("highscore.txt");\
    if (highscoreFile.is_open()) {
        highscoreFile << highscore;
        highscoreFile.close();
    } else {
        std::cerr << "Failed to save highscore to file" << std::endl;
    }
}

int Game::loadHighScore()
{
    int loadedHighScore = 0;
    std::ifstream highscoreFile("highscore.txt");
    if (highscoreFile.is_open()) {
        highscoreFile >> loadedHighScore;
        highscoreFile.close();
    } else {
        std::cerr << "Failed to load highscore from file" << std::endl;
    }
    return loadedHighScore;
}
