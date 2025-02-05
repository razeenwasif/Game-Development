#include <iostream>
#include "../include/neuron.hpp"
#include "../include/matrix.hpp"
#include "../include/neuralnet.hpp"
#include <cassert>

// https://www.youtube.com/watch?v=CiQC3uSOW4g&list=PL2-7U6BzddIYBOl98DDsmpXiTcj1ojgJG&index=4

int main(int argc, char **argv) {

    Neuron *n = new Neuron(1.5);
    std::cout << "Value: " << n -> getValue() << std::endl;
    std::cout << "Activated Value: " << n -> getActivatedValue() << std::endl;
    std::cout << "Derived Value: " << n -> getDerivedValue() << std::endl;

    Matrix *m = new Matrix(3, 2, true);
    m -> printToConsole();

    std::cout << "--------------------" << std::endl;

    // transpose matrix
    Matrix *mt = m -> transpose();
    mt -> printToConsole();

    std::cout << "--------------------" << std::endl;

    std::vector<double> input;
    input.push_back(1.0);
    input.push_back(0.0);
    input.push_back(1.0);

    std::vector<int> topology;
    topology.push_back(3);
    topology.push_back(2);
    topology.push_back(3);

    NeuralNet *nn = new NeuralNet(topology);
    nn -> setCurrentInput(input);
    nn -> setCurrentTarget(input);
    nn -> feedForward();
    nn -> printToConsole();

    std::cout << "--------------------" << std::endl;

    nn -> setErrors();  
    std::cout << "Total Error: " << nn -> getTotalError() << std::endl;

    // cmake .
    // make
    // exec: ./neuralNetwork
    return 0;
}