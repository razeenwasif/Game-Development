#pragma once
#include <vector>
#include "block.hpp"

class Barrier {
    public:
        Barrier(Vector2 position);
        void draw();
        Vector2 position;
        std::vector<Block> blocks;
        static std::vector<std::vector<int>> grid;

    private:

};