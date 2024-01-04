#pragma once

#include <vector>
#include "Neuron.h"

class Layer {
    friend Neuron;

public:
    Layer(int num_neurons, int num_neurons_prev);
    void forwardProp(Layer &prevLayer);
    void setNeuronVals(std::vector<double> &vals);

private:
    std::vector<Neuron> neurons;
};
