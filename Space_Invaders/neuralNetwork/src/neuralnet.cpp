#include "../include/neuralnet.hpp"

NeuralNet::NeuralNet(std::vector<int> topology)
{
    this -> topology = topology;
    for (int i = 0; i < topology.size(); i++) {
        Layer *l = new Layer(topology[i]);
        this -> layers.push_back(l);
    }

    for (int i = 0; i < topology.size() - 1; i++) {
        Matrix *m = new Matrix(topology[i], topology[i + 1], true);
        this -> weights.push_back(m);
    }
}

void NeuralNet::feedForward() {
    for (int i = 0; i < (this -> layers.size() - 1); i++) {
        Matrix *a = this -> getNeuronMatrix(i);

        if (i != 0) {
            a = this -> getActivatedNeuronMatrix(i);
        }

        Matrix *b = this -> getWeights(i);
        Matrix *c = (new utils::matrixMultiply(a, b)) -> execute();

        std::vector<double> values;
        for (int j = 0; j < c -> getNumCols(); j++) {
            this -> setNeuronValue(i + 1, j, c -> getValue(0, j));
        }
    }
}

void NeuralNet::setCurrentInput(std::vector<double> input)
{
    this -> input = input;
    for (int i = 0; i < input.size(); i++) {
        this -> layers[0] -> setValues(i, input[i]);
    }
}

void NeuralNet::printToConsole()
{
    for(int i = 0; i < this -> layers.size(); i++) {
        std::cout << "Layer: " << i << std::endl;
        if (i == 0) {
            Matrix *m = this -> layers[i] -> matrixifyValues();
            m -> printToConsole();
        } else {
            Matrix *m = this -> layers[i] -> matrixifyActivatedValues();
            m -> printToConsole();
        }
        std::cout << "++++++++++++++++++++" << std::endl;
        if (i < this -> layers.size() - 1) {
            std::cout << "weight matrix: " << i << std::endl;
            this -> getWeights(i) -> printToConsole();
        }
        std::cout << "++++++++++++++++++++" << std::endl;
    }
}
