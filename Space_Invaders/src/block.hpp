#pragma once
#include <raylib.h>

class Block {
    public:
        Block(Vector2 position);
        void draw();

    private:
        Vector2 position;
};