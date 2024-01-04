#include "Layer.h"

Layer::Layer(int num_neurons, int num_neurons_prev) {
    for (int i = 0; i < num_neurons; i++) {
        this->neurons.emplace_back(i, num_neurons_prev);
    }
}

void Layer::forwardProp(Layer &prevLayer) {
    for (Neuron &n: this->neurons)
        n.forwardProp(prevLayer);
}

void Layer::setNeuronVals(std::vector<double> &vals) {
    for (int i = 0; i < vals.size() && i < this->neurons.size(); i++)
        this->neurons[i].setActivationVal(vals[i]);
}
