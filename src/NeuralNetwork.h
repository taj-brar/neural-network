#pragma once

#include <vector>
#include "Layer.h"

class NeuralNetwork {
public:
    explicit NeuralNetwork(const std::vector<int> &topology);
    void train();
    int predict();

private:
    std::vector<Layer> layers;

    void forwardProp();
    void backProp();
};
