#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_
#include <iostream>
#include <vector>
#include <cmath>

class Matrix {
    public:
        Matrix(int numRows, int numCols, bool isRandom);
        Matrix *transpose();
        double generateRandomNumber();
        void setValue(int row, int col, double value) {
            if (row >= 0 && row < numRows && col >= 0 && col < numCols) {
                values[row][col] = value;
            } else {
                std::cerr << "Index out of bounds" << std::endl;
            }
        }
        double getValue(int row, int col);
        void printToConsole();
        int getNumRows() { return this->numRows; }
        int getNumCols() { return this->numCols; }

    private:
        int numRows, numCols; bool isRandom;
        std::vector<std::vector<double>> values; 
        
};
#endif