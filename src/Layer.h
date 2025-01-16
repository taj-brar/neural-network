#pragma once

#include <vector>
#include "Neuron.h"

class Layer {
    friend Neuron;

public:
    Layer(int num_neurons, int num_neurons_prev);
    void forwardProp(Layer &prevLayer);
    void setNeuronVals(const std::vector<double> &vals);
    void getNeuronVals(std::vector<double> &resultVals);
    double getOutputError(const std::vector<double> &targetVals);
    void calcGradientOutput(const std::vector<double> &targetVals);
    void calcGradientHidden(const Layer &nextLayer);
    void updateWeights(const Layer &prevLayer);

private:
    std::vector<Neuron> neurons;
};
