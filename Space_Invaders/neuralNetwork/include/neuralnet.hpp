#ifndef _NEURALNET_HPP_
#define _NEURALNET_HPP_
#include "neuron.hpp"
#include "matrix.hpp"
#include "layer.hpp"
#include "utils/matrixMultiply.hpp"
#include <iostream>
#include <vector>
#include <cmath>

#define COST_MSE 1

class NeuralNet {
    public:
        NeuralNet(std::vector<int> topology);
        void feedForward();
        void setCurrentInput(std::vector<double> input);
        void setCurrentTarget(std::vector<double> target) {this -> target = target;}
        void printToConsole();
        void setNeuronValue(int idxLayer, int idxNeuron, double value) {
            this -> layers[idxLayer] -> setValues(idxNeuron, value);
        }
        void setErrors();
        double getTotalError() { return this -> error; }
        std::vector<double> getErrors() { return this -> errors; }

        Matrix *getNeuronMatrix(int idx) { return this -> layers[idx] -> matrixifyValues(); }
        Matrix *getDerivedNeuronMatrix(int idx) { return this -> layers[idx] -> matrixifyDerivedValues(); }
        Matrix *getActivatedNeuronMatrix(int idx) { return this -> layers[idx] -> matrixifyActivatedValues(); }
        Matrix *getWeights(int idx) { return this -> weights[idx]; }

    private:
        std::vector<int> topology;
        std::vector<Layer *> layers;
        std::vector<Matrix *> weights; // size of topology - 1
        std::vector<double> input;
        std::vector<double> target;
        double error;
        std::vector<double> errors;
        std::vector<double> historicalErrors;
};

#endif