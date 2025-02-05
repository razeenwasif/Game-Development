#include "../include/neuron.hpp"

// Constructor: Initializes the neuron with the given value
Neuron::Neuron(double value) {
    this->value = value;
}

// Sets the value of the neuron and updates the activated and derived values
void Neuron::setValue(double value) {
    this->value = value;
    activate();
    derive();
}

// Activation function (fast sigmoid: f(x) = x / (1 + |x|))
void Neuron::activate()
{
    this->activatedValue = this->value / (1 + std::abs(this->value));
}

// Derivative of the activation function (f'(x) = f(x) * (1 - f(x)))
void Neuron::derive()
{
    this->derivedValue = this->activatedValue * (1 - this->activatedValue);
}
