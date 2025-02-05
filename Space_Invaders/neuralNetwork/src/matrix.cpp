#include "../include/matrix.hpp"
#include <random>   

Matrix::Matrix(int numRows, int numCols, bool isRandom)
{
    this -> numRows = numRows;
    this -> numCols = numCols;

    for (int i = 0; i < numRows; i++) {
        std::vector<double> row;
        for (int j = 0; j < numCols; j++) {
            if (isRandom) {
                row.push_back(generateRandomNumber());
            } else {
                row.push_back(0.0);
            }
        }
        values.push_back(row);
    }
}

Matrix *Matrix::transpose()
{
    Matrix *m = new Matrix(this -> numCols, this -> numRows, false);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            m -> setValue(j, i, this -> values[i][j]);
        }
    }
    return m;
}

double Matrix::generateRandomNumber()
{
    std::random_device rd;
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<> dis(0, 1);
    return dis(gen);
}

// void Matrix::setValue(int row, int col, double value)
// {
//     if (row >= 0 && row < numRows && col >= 0 && col < numCols) {
//         values[row][col] = value;
//     }
// }

double Matrix::getValue(int row, int col)
{
    if (row >= 0 && row < numRows && col >= 0 && col < numCols) {
        return values[row][col];
    }
    return 0.0;
}

void Matrix::printToConsole()
{
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            std::cout << this -> values[i][j] << "\t\t";
        }
        std::cout << std::endl;
    }
}
