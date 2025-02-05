#include "../include/utils/matrixMultiply.hpp"

utils::matrixMultiply::matrixMultiply(Matrix *a, Matrix *b)
{
    this -> a = a; this -> b = b;

    if (a -> getNumCols() != b -> getNumRows()) {
        std::cerr << "Matrix dimensions do not match for multiplication" << std::endl;
        exit(1);
    }

    this -> c = new Matrix(a -> getNumRows(), b -> getNumCols(), false);
}

Matrix *utils::matrixMultiply::execute()
{
    for(int i = 0; i < a -> getNumRows(); i++) {
        for(int j = 0; j < b -> getNumCols(); j++) {
            for(int k = 0; k < b -> getNumRows(); k++) {
                double product = this -> a -> getValue(i, k) * this -> b -> getValue(k, j);
                double newValue = this -> c -> getValue(i, j) + product;
                this -> c -> setValue(i, j, newValue);
            }
        }
    }
    return this -> c;
}
