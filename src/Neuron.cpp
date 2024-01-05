#include "Neuron.h"
#include "Layer.h"
#include <random>

Neuron::Neuron(int index, int numPrevConns, double initActivationVal) {
    this->index = index;
    this->activationValue = initActivationVal;

    // set random weights to start
    for (int i = 0; i < numPrevConns; i++) {
        this->prevConns.emplace_back();
        this->prevConns[i].weight = getRandWeight();
        this->prevConns[i].deltaWeight = 0;
    }
}

void Neuron::forwardProp(Layer &prevLayer) {
    double sum = 0;

    for (int i = 0; i < prevLayer.neurons.size(); i++) {
        Neuron n = prevLayer.neurons[i];
        sum += n.activationValue * this->prevConns[i].weight;
    }

    this->activationValue = activationFunc(sum);
}

void Neuron::setActivationVal(double newVal) {
    this->activationValue = newVal;
}

double Neuron::getRandWeight() {
    return rand() / double(RAND_MAX); // NOLINT(*-msc50-cpp)
}

double Neuron::activationFunc(double x) {
    return tanh(x);
}

double Neuron::activationFuncDeriv(double x) {
    return 1.0 - x*x;
}