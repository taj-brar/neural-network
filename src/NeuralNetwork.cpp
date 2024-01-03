#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(const std::vector<int> &topology) {
    for (int i = 0; i < topology.size(); i++) {
        // get num of neuron in prev layer
        int num_neurons_prev = i == 0 ? 0 : topology[i - 1];
        this->layers.emplace_back(topology[i], num_neurons_prev);
    }
}