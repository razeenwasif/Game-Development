#include "../include/layer.hpp"

// Constructor: Initializes the layer with the given size
Layer::Layer(int size)
{
    this->size = size;
    // Create neurons for the layer
    for (int i = 0; i < size; i++) {
        Neuron *n = new Neuron(0.0);
        this->neurons.push_back(n);
    }
}

// Sets the value of a neuron at the given index
void Layer::setValues(int index, double value)
{
    if (index >= 0 && index < size) {
        this->neurons[index]->setValue(value);
    }
}

std::vector<double> Layer::getActivatedValues()
{
    std::vector<double> activatedValues;
    for (int i = 0; i < neurons.size(); i++) {
        activatedValues.push_back(this->neurons[i]->getActivatedValue());
    }
    return activatedValues;
}

// Converts the neuron values to a matrix
Matrix *Layer::matrixifyValues()
{
    Matrix *m = new Matrix(1, this->size, false);
    for (int i = 0; i < size; i++) {
        m->setValue(0, i, this->neurons[i]->getValue());
    }
    return m;
}

// Converts the derived values of the neurons to a matrix
Matrix *Layer::matrixifyDerivedValues()
{
    Matrix *m = new Matrix(1, size, false);
    for (int i = 0; i < size; i++) {
        m->setValue(0, i, this->neurons[i]->getDerivedValue());
    }
    return m;
}

// Converts the activated values of the neurons to a matrix
Matrix *Layer::matrixifyActivatedValues()
{
    Matrix *m = new Matrix(1, size, false);
    for (int i = 0; i < size; i++) {
        m->setValue(0, i, this->neurons[i]->getActivatedValue());
    }
    return m;
}
