#include <raylib.h>
#include "game.hpp"
#include "neat.hpp"

// F5 to run program

int main() {

    Color grey = {29, 29, 27, 255};
    int windowWidth = 750, windowHeight = 700;
    // initialise the window
    InitWindow(windowWidth, windowHeight, "Space Invaders");
    SetTargetFPS(60);

    // Create game object
    Game game;

    // game loop
    while (WindowShouldClose() == false) { // check if escape key is pressed
        
        // handle inputs
        game.handleInput();

        // handle game logic
        game.update();

        // draw game
        BeginDrawing();
        ClearBackground(grey);

        game.draw();

        EndDrawing();

    }

    CloseWindow();
}