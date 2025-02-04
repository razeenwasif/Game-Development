#pragma once
#include <raylib.h>

class Block {
    public:
        Block(Vector2 position);
        void draw();
        Rectangle getRect();

    private:
        Vector2 position;
};