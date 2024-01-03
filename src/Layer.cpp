#include "Layer.h"

Layer::Layer(int num_neurons, int num_neurons_prev) {
    for (int i = 0; i < num_neurons; i++) {
        this->neurons.emplace_back(i, num_neurons_prev);
    }
}