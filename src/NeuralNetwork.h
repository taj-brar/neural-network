#pragma once

#include <vector>
#include "Layer.h"

class NeuralNetwork {
public:
    explicit NeuralNetwork(const std::vector<int> &topology);
    void train(const std::vector<int> &input1, const std::vector<int> &input2, const std::vector<int> &output);
    void predict(const std::vector<double> &inputs, std::vector<double> &results);

private:
    std::vector<Layer> layers;

    void forwardProp();
    void backProp(const std::vector<double> &targetVals);
};
