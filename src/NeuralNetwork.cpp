#include "NeuralNetwork.h"
#include "Layer.h"

NeuralNetwork::NeuralNetwork(const std::vector<int> &neuron_config) {
    for (int curr_layer_size : neuron_config) {
        this->layers.emplace_back(curr_layer_size);
    }
}