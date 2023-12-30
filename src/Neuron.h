#pragma once
#include <vector>

class Neuron {
private:
    float activation;
    std::vector<int> prev_connections;
};
