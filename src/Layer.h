#pragma once

#include <vector>
#include "Neuron.h"

class Layer {
    friend Neuron;

public:
    Layer(int num_neurons, int num_neurons_prev);

private:
    std::vector<Neuron> neurons;
};
