#include "NeuralNetwork.h"
#include <cstdio>

NeuralNetwork::NeuralNetwork(const std::vector<int> &topology) {
    // create layers with an additional bias neuron
    for (int i = 0; i < topology.size(); i++) {
        // get num of neuron in prev layer
        int num_neurons_prev = i == 0 ? 0 : topology[i - 1] + 1;
        this->layers.emplace_back(topology[i] + 1, num_neurons_prev);
    }
}

void NeuralNetwork::forwardProp() {
    // start forward propagation at second layer
    for (int i = 1; i < this->layers.size(); i++) {
        Layer &prevLayer = this->layers[i - 1];
        Layer &currLayer = this->layers[i];
        currLayer.forwardProp(prevLayer);
    }
}

void NeuralNetwork::backProp(const std::vector<double> &targetVals) {
    printf("%f\n", layers.back().getOutputError(targetVals));

    // calculate gradient for output layer
    layers.back().calcGradientOutput(targetVals);

    // calculate gradients for hidden layers
    for (unsigned i = layers.size() - 2; i > 0; i--) {
        Layer &currLayer = layers[i];
        Layer &nextLayer = layers[i + 1];

        currLayer.calcGradientHidden(nextLayer);
    }

    // update all weights
    for (unsigned i = layers.size() - 1; i > 0; i--) {
        Layer &currLayer = layers[i];
        Layer &prevLayer = layers[i - 1];

        currLayer.updateWeights(prevLayer);
    }
}

void NeuralNetwork::train(const std::vector<int> &input1, const std::vector<int> &input2, const std::vector<int> &output) {
    // temporary implementation for testing
    for (int i = 0; i < input1.size() && i < input2.size() && i < output.size(); i++) {
        std::vector<double> inputs{static_cast<double>(input1[i]), static_cast<double>(input2[i])};
        this->layers[0].setNeuronVals(inputs);
        forwardProp();
        backProp(std::vector<double>{static_cast<double>(output[i])});
    }
}

void NeuralNetwork::predict(const std::vector<double> &inputs, std::vector<double> &results) {
    // predict
    layers[0].setNeuronVals(inputs);
    forwardProp();

    // place results in container
    results.clear();
    layers.back().getNeuronVals(results);
}