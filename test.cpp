#include "NeuralNetwork.h"
#include <cstdio>
#include <vector>

int main() {
    std::printf("Running test file.\n\n");
    std::vector<int> v{10, 2, 614, 1265};
    NeuralNetwork nn = NeuralNetwork(v);
}