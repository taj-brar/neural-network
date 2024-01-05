#include "Layer.h"

Layer::Layer(int num_neurons, int num_neurons_prev) {
    for (int i = 0; i < num_neurons; i++) {
        // set activation value of bias neurons to 1 and all others to 0
        this->neurons.emplace_back(i, num_neurons_prev,
                                   i == num_neurons - 1 ? 1.0 : 0.0);
    }
}

void Layer::forwardProp(Layer &prevLayer) {
    // propagate forward on all neurons except bias neurons
    for (int i = 0; i < this->neurons.size() - 1; i++)
        this->neurons[i].forwardProp(prevLayer);
}

void Layer::setNeuronVals(std::vector<double> &vals) {
    for (int i = 0; i < vals.size() && i < this->neurons.size(); i++)
        this->neurons[i].setActivationVal(vals[i]);
}
