#include "Neuron.h"
#include "Layer.h"
#include <random>

double Neuron::ETA = 0.15;
double Neuron::ALPHA = 0.5;

Neuron::Neuron(int index, int numPrevConns, double initActivationVal) {
    this->index = index;
    this->activationValue = initActivationVal;
    this->gradient = 0.0;

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

void Neuron::calcGradientOutput(double targetVal) {
    this->gradient = (targetVal - this->activationValue) * activationFuncDeriv(this->activationValue);
}

void Neuron::calcGradientHidden(const Layer &nextLayer) {
    this->gradient = sumDerivsOfWeights(nextLayer) * activationFuncDeriv(this->activationValue);
}

void Neuron::updateWeights(const Layer &prevLayer) {
    for (int i = 0; i < this->prevConns.size(); i++) {
        double oldDeltaWeight = this->prevConns[i].deltaWeight;
        double newDeltaWeight = ETA * this->gradient * prevLayer.neurons[i].activationValue
                + ALPHA * oldDeltaWeight;

        this->prevConns[i].deltaWeight = newDeltaWeight;
        this->prevConns[i].weight += newDeltaWeight;
    }
}

double Neuron::sumDerivsOfWeights(const Layer &nextLayer) const {
    double sum = 0.0;

    for (int i = 0; i < nextLayer.neurons.size() - 1; i++) {
        // SUM ALL: (gradient of other neuron) x (weight b/w neurons)
        sum += nextLayer.neurons[i].gradient * nextLayer.neurons[i].prevConns[this->index].weight;
    }

    return sum;
}

double Neuron::getRandWeight() {
    return rand() / double(RAND_MAX); // NOLINT(*-msc50-cpp)
}

double Neuron::activationFunc(double x) {
    return tanh(x);
}

double Neuron::activationFuncDeriv(double x) {
    return 1.0 - x * x;
}
