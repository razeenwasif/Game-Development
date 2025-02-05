#include "../include/utils/matrixToVector.hpp"

utils::MatrixToVector::MatrixToVector(Matrix *a)
{
    this -> a = a;
}

std::vector<double> utils::MatrixToVector::execute()
{
    std::vector<double> result;
    for(int i = 0; i < a -> getNumRows(); i++) {
        for(int j = 0; j < a -> getNumCols(); j++) {
            result.push_back(a -> getValue(i, j));
        }
    }
    return result;
}