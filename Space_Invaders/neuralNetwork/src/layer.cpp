#include "../include/layer.hpp"

Layer::Layer(int size)
{
    this -> size = size;
    for (int i = 0; i < size; i++) {
        Neuron *n = new Neuron(0.0);
        this -> neurons.push_back(n);
    }
}

void Layer::setValues(int index, double value)
{
    if (index >= 0 && index < size) {
        this -> neurons[index] -> setValue(value);
    }
}

Matrix *Layer::matrixifyValues()
{
    Matrix *m = new Matrix(1, this -> size, false);
    for (int i = 0; i < size; i++) {
        m -> setValue(0, i, this -> neurons[i] -> getValue());
    }
    return m;
}

Matrix *Layer::matrixifyDerivedValues()
{
    Matrix *m = new Matrix(1, size, false);
    for (int i = 0; i < size; i++) {
        m -> setValue(0, i, this -> neurons[i] -> getDerivedValue());
    }
    return m;
}

Matrix *Layer::matrixifyActivatedValues()
{
    Matrix *m = new Matrix(1, size, false);
    for (int i = 0; i < size; i++) {
        m -> setValue(0, i, this -> neurons[i] -> getActivatedValue());
    }
    return m;
}
