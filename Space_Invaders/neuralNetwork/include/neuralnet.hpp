#ifndef _NEURALNET_HPP_
#define _NEURALNET_HPP_
#include "neuron.hpp"
#include "matrix.hpp"
#include "layer.hpp"
#include "utils/matrixMultiply.hpp"
#include <iostream>
#include <vector>
#include <cmath>

class NeuralNet {
    public:
        NeuralNet(std::vector<int> topology);
        void feedForward();
        void setCurrentInput(std::vector<double> input);
        void printToConsole();
        void setNeuronValue(int idxLayer, int idxNeuron, double value) {
            this -> layers[idxLayer] -> setValues(idxNeuron, value);
        }

        Matrix *getNeuronMatrix(int idx) { return this -> layers[idx] -> matrixifyValues(); }
        Matrix *getDerivedNeuronMatrix(int idx) { return this -> layers[idx] -> matrixifyDerivedValues(); }
        Matrix *getActivatedNeuronMatrix(int idx) { return this -> layers[idx] -> matrixifyActivatedValues(); }
        Matrix *getWeights(int idx) { return this -> weights[idx]; }

    private:
        std::vector<int> topology;
        std::vector<Layer *> layers;
        std::vector<Matrix *> weights; // size of topology - 1
        std::vector<double> input;
};

#endif