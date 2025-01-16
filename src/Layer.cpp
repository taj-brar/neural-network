#include "Layer.h"
#include <cmath>

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

void Layer::setNeuronVals(const std::vector<double> &vals) {
    for (int i = 0; i < vals.size() && i < this->neurons.size(); i++)
        this->neurons[i].setActivationVal(vals[i]);
}

void Layer::getNeuronVals(std::vector<double> &resultVals) {
    // exclude bias neuron
    for (int i = 0; i < this->neurons.size() - 1; i++)
        resultVals.push_back(neurons[i].activationValue);
}

double Layer::getOutputError(const std::vector<double> &targetVals) {
    double error = 0.0;

    // calculate root-mean-square (RMS)
    // get sum of difference squared
    for (int i = 0; i < this->neurons.size() - 1; i++) {
        double delta = targetVals[i] - this->neurons[i].activationValue;
        error += delta * delta;
    }
    // get average of differences squared
    error = error / int(this->neurons.size() - 1);
    // get RMS
    error = sqrt(error);

    return error;
}

void Layer::calcGradientOutput(const std::vector<double> &targetVals) {
    // exclude bias neuron
    for (int i = 0; i < neurons.size() - 1; i++)
        neurons[i].calcGradientOutput(targetVals[i]);
}

void Layer::calcGradientHidden(const Layer &nextLayer) {
    // exclude bias neuron
    for (int i = 0; i < neurons.size() - 1; i++)
        neurons[i].calcGradientHidden(nextLayer);
}

void Layer::updateWeights(const Layer &prevLayer) {
    // exclude bias neuron
    for (int i = 0; i < neurons.size() - 1; i++)
        neurons[i].updateWeights(prevLayer);
}
