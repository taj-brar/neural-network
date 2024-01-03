#include "NeuralNetwork.h"
#include <cstdio>
#include <vector>

int main() {
    std::printf("Running test file.\n\n");

    // create neural net
    std::vector<int> v{2, 4, 2};
    NeuralNetwork nn = NeuralNetwork(v);

    std::printf("Tests completed successfully.\n\n");
}