#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_
#include <iostream>
#include <vector>
#include <cmath>

class Matrix {
    public:
        // Constructor: Initializes the matrix with the given dimensions and random values if specified
        Matrix(int numRows, int numCols, bool isRandom);
        // Transposes the matrix
        Matrix *transpose();
        // Generates a random number between 0 and 1
        double generateRandomNumber();
        // Sets the value at the specified row and column
        void setValue(int row, int col, double value) {
            if (row >= 0 && row < numRows && col >= 0 && col < numCols) {
                values[row][col] = value;
            } else {
                std::cerr << "Index out of bounds" << std::endl;
            }
        }
        // Gets the value at the specified row and column
        double getValue(int row, int col);
        // Prints the matrix to the console
        void printToConsole();
        // Gets the number of rows in the matrix
        int getNumRows() { return this->numRows; }
        // Gets the number of columns in the matrix
        int getNumCols() { return this->numCols; }

    private:
        int numRows, numCols; bool isRandom;
        std::vector<std::vector<double>> values; 
        
};
#endif