#include "NeuralNetwork.h"

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

void NeuralNetwork::train() {
    // temporary implementation for testing
    std::vector<double> v{0.5 ,0.3};
    this->layers[0].setNeuronVals(v);
    forwardProp();
}