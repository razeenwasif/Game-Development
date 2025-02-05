#include "../include/neuron.hpp"

Neuron::Neuron(double value) {
    this->value = value;
}

void Neuron::setValue(double value) {
    this->value = value;
    activate();
    derive();
}

// f(x) = x / (1 + |x|)
void Neuron::activate()
{
    this -> activatedValue = this -> value / (1 + std::abs(this -> value));
}

// f'(x) = f(x) * (1 - f(x))
void Neuron::derive()
{
    this -> derivedValue = this -> activatedValue * (1 - this -> activatedValue);
}
