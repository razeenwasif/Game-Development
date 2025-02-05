#ifndef _NEURON_HPP_
#define _NEURON_HPP_
#include <iostream>
#include <vector>
#include <cmath>

class Neuron {
    public:
        // Constructor: Initializes the neuron with the given value
        Neuron(double value);

        // Sets the value of the neuron
        void setValue(double value);
        
        // Activation function (fast sigmoid: f(x) = x / (1 + |x|))
        void activate();
        // Derivative of the activation function (f'(x) = f(x) * (1 - f(x)))
        void derive();

        // Gets the value of the neuron
        double getValue() { return this->value; }
        // Gets the activated value of the neuron
        double getActivatedValue() { return this->activatedValue; }
        // Gets the derived value of the neuron
        double getDerivedValue() { return this->derivedValue; }

    private:
        double value; // weighted sum of inputs
        double activatedValue; // normalized weighted sum of inputs
        double derivedValue; // approximated derivative of the activation function
};

#endif