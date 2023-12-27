#pragma once
#include <vector>
#include "Layer.h"

class NeuralNetwork {
public:
    NeuralNetwork(const std::vector<int> &neuron_config);

    void train();

    int predict();

private:
    std::vector<Layer> layers;

    void forward_prop();

    void back_prop();
};
