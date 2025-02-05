#ifndef _LAYER_HPP_
#define _LAYER_HPP_
#include "neuron.hpp"
#include "matrix.hpp"
#include <iostream>
#include <vector>
#include <cmath>

class Layer {
    public:
        // Constructor: Initializes the layer with the given size
        Layer(int size);

        // Setters
        void setValues(int index, double value);
        void setNeuron(std::vector<Neuron *> neurons) { this -> neurons = neurons; }

        // getters
        std::vector<double> getActivatedValues();
        std::vector<Neuron *> getNeurons() { return this -> neurons; }

        // Converts the neuron values to a matrix
        Matrix *matrixifyValues();
        // Converts the derived values of the neurons to a matrix
        Matrix *matrixifyDerivedValues();
        // Converts the activated values of the neurons to a matrix
        Matrix *matrixifyActivatedValues();


    private:
        int size;
        std::vector<Neuron *> neurons; // instantiate neurons
        
};
#endif