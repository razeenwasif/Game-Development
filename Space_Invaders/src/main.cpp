#include <raylib.h>
#include <string>
#include "headers/game.hpp"

// F5 to run program or ./game.exe

std::string formatWithLeadingZeros(int number, int width) {
    std::string numberText = std::to_string(number);
    int leadingZeros = width - numberText.length();
    return numberText = std::string(leadingZeros, '0') + numberText;
}

int main() {

    Color grey = {29, 29, 27, 255};
    Color yellow = {243, 216, 63, 255};
    int offset = 50, windowWidth = 750, windowHeight = 700;
    // initialise the window
    InitWindow(windowWidth + offset, windowHeight + 2*offset, "Space Invaders");
    SetTargetFPS(120);

    InitAudioDevice();
    Font font = LoadFontEx("assets/monogram.ttf", 64, 0, 0);
    Texture2D spaceshipImage = LoadTexture("assets/spaceship.png");

    // Create game object
    Game game;

    // game loop
    while (WindowShouldClose() == false) { // check if escape key is pressed

        // audio
        UpdateMusicStream(game.music);
        
        // handle inputs
        game.handleInput();

        // handle game logic
        game.update();

        if (IsKeyPressed(KEY_I)) {
            game.currentMode = (game.currentMode == Game::PLAYER_MODE) ? Game::AI_MODE : Game::PLAYER_MODE;
            game.reset();
            game.initGame();
        }

        // draw game
        BeginDrawing();
        ClearBackground(grey);
        DrawRectangleRoundedLines({10, 10, 780, 780}, 0.18f, 20, yellow);
        DrawLineEx({25, 730}, {775, 730}, 3, yellow);

        if (game.run) {
            DrawTextEx(font, "LEVEL 01", {570, 740}, 34, 2, yellow);
        } else {
            DrawTextEx(font, "GAME OVER", {570, 740}, 34, 2, yellow);
        }

        float x = 50.0;
        for (int i = 0; i < game.lives; i++) {
            DrawTextureV(spaceshipImage, {x, 745}, WHITE);
            x += 50;
        }
        DrawTextEx(font, "SCORE", {50, 15}, 34, 2, yellow);
        std::string scoreText = formatWithLeadingZeros(game.score, 5);
        DrawTextEx(font, scoreText.c_str(), {50, 40}, 34, 2, yellow);

        DrawTextEx(font, "HI-SCORE", {570, 15}, 34, 2, yellow);
        std::string highscoreText = formatWithLeadingZeros(game.highscore, 5);
        DrawTextEx(font, highscoreText.c_str(), {655, 40}, 34, 2, yellow);

        game.draw();

        EndDrawing();

    }

    CloseWindow();
    CloseAudioDevice();
}