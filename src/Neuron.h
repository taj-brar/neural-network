#pragma once

#include <vector>

class Layer;

struct Connection {
    double weight;
    double deltaWeight;
};

class Neuron {
public:
    friend Layer;
    Neuron(int index, int numPrevConns, double initActivationVal);
    void forwardProp(Layer &prevLayer);
    void setActivationVal(double newVal);
    void calcGradientOutput(double targetVal);
    void calcGradientHidden(const Layer &nextLayer);
    void updateWeights(const Layer &prevLayer);

private:
    static double ETA;
    static double ALPHA;
    int index;
    double activationValue;
    double gradient;
    std::vector<Connection> prevConns;

    static double getRandWeight();
    static double activationFunc(double x);
    static double activationFuncDeriv(double x);
    double sumDerivsOfWeights(const Layer &nextLayer) const;
};
