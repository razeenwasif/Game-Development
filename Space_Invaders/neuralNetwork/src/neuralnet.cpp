#include "../include/neuralnet.hpp"
#include "../include/neuron.hpp"
#include "../include/layer.hpp"
#include <cassert>

// Constructor: Initializes the neural network with the given topology
NeuralNet::NeuralNet(std::vector<int> topology)
{
    this->topology = topology;
    // Create layers based on the topology
    for (int i = 0; i < static_cast<int>(topology.size()); i++) {
        Layer *l = new Layer(topology[i]);
        this->layers.push_back(l);
    }

    // Create weight matrices between layers
    for (int i = 0; i < static_cast<int>(topology.size()) - 1; i++) {
        Matrix *m = new Matrix(topology[i], topology[i + 1], true);
        this->weights.push_back(m);
    }
}

// Feeds the input through the network
void NeuralNet::feedForward() {
    for (int i = 0; i < static_cast<int>(this->layers.size() - 1); i++) {
        Matrix *a = this->getNeuronMatrix(i);

        if (i != 0) {
            a = this->getActivatedNeuronMatrix(i);
        }

        Matrix *b = this->getWeights(i);
        Matrix *c = (new utils::matrixMultiply(a, b))->execute();

        // Set the values of the next layer
        for (int j = 0; j < c->getNumCols(); j++) {
            this->setNeuronValue(i + 1, j, c->getValue(0, j));
        }
    }
}

// Sets the current input values for the network
void NeuralNet::setCurrentInput(std::vector<double> input)
{
    this->input = input;
    for (int i = 0; i < static_cast<int>(input.size()); i++) {
        this->layers[0]->setValues(i, input[i]);
    }
}

// Prints the network's layers and weights to the console
void NeuralNet::printToConsole()
{
    for(int i = 0; i < static_cast<int>(this->layers.size()); i++) {
        std::cout << "Layer: " << i << std::endl;
        if (i == 0) {
            Matrix *m = this->layers[i]->matrixifyValues();
            m->printToConsole();
        } else {
            Matrix *m = this->layers[i]->matrixifyActivatedValues();
            m->printToConsole();
        }
        std::cout << "++++++++++++++++++++" << std::endl;
        if (i < static_cast<int>(this->layers.size() - 1)) {
            std::cout << "weight matrix: " << i << std::endl;
            this->getWeights(i)->printToConsole();
        }
        std::cout << "++++++++++++++++++++" << std::endl;
    }
}

void NeuralNet::setErrors()
{
    if (this -> target.size() == 0) {
        std::cerr << "No target set for neural network" << std::endl;
        assert(false);
    }
    if (this -> target.size() != this -> layers[this -> layers.size() - 1] ->  getNeurons().size()) {
        std::cerr << "Target size does not match output layer size: " << this -> layers[this -> layers.size() - 1] ->  getNeurons().size() << std::endl;
        assert(false);
    }
    this -> error = 0.0;
    int outputLayerIdx = this -> layers.size() - 1;
    std::vector<Neuron *> outputNeurons = this -> layers[outputLayerIdx] -> getNeurons();
    for (int i = 0; i < static_cast<int>(target.size()); i++) {
        double tempErr = (outputNeurons[i] -> getActivatedValue() - target[i]);
        errors[i] = tempErr;
        this -> error += tempErr;
    }

    historicalErrors.push_back(this -> error);
}

