#pragma once

#include <vector>

class Layer;

struct Connection {
    double weight;
    double deltaWeight;
};

class Neuron {
public:
    Neuron(int index, int numPrevConns, double initActivationVal);
    void forwardProp(Layer &prevLayer);
    void setActivationVal(double newVal);

private:
    int index;
    double activationValue;
    std::vector<Connection> prevConns;

    static double getRandWeight();
    static double activationFunc(double x);
    static double activationFuncDeriv(double x);
};
