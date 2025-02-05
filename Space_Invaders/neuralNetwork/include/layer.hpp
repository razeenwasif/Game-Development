#ifndef _LAYER_HPP_
#define _LAYER_HPP_
#include "neuron.hpp"
#include "matrix.hpp"
#include <iostream>
#include <vector>
#include <cmath>

class Layer {
    public:
        Layer(int size);
        void setValues(int index, double value);
        Matrix *matrixifyValues();
        Matrix *matrixifyDerivedValues();
        Matrix *matrixifyActivatedValues();

    private:
        int size;
        std::vector<Neuron *> neurons; // instantiate neurons
        
};
#endif