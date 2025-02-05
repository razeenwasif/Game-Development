#ifndef _NEURON_HPP_
#define _NEURON_HPP_
#include <iostream>
#include <vector>
#include <cmath>

class Neuron {
    public:
        Neuron(double value);

        void setValue(double value);
        
        // activation function (fast sigmoid: f(x) = x / (1 + |x|))
        void activate();
        // derivative of the activation function (f'(x) = f(x) * (1 - f(x)))
        void derive();

        double getValue() { return this -> value; }
        double getActivatedValue() { return this -> activatedValue; }
        double getDerivedValue() { return this -> derivedValue; }

    private:
        double value; // weighted sum of inputs
        double activatedValue; // normalize weighted sum of inputs
        double derivedValue; // approximated derivative of the activation function
};

#endif