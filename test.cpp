#include "NeuralNetwork.h"
#include <cstdio>
#include <vector>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

void split(const std::string &s, char delimiter, std::vector<int> &tokens);

int main() {
    std::printf("Running test file.\n\n");

    // read data
    std::vector<int> input1;
    std::vector<int> input2;
    std::vector<int> output;
    std::printf("Reading file.\n");
    std::ifstream file("data/xor.csv");
    if (file.is_open()) {
        std::string s;
        std::vector<int> tokens;
        std::getline(file, s); // skip first line
        while (file) {
            std::getline(file, s);
            if (!s.empty()) {
                split(s, ',', tokens);
                input1.push_back(tokens[0]);
                input2.push_back(tokens[1]);
                output.push_back(tokens[2]);
                tokens.clear();
            }
        }
    } else
        std::printf("FILE NOT OPEN\n");


    // create neural net
    std::vector<int> topology{2, 4, 1};
    NeuralNetwork nn = NeuralNetwork(topology);

    nn.train(input1, input2, output);

    std::vector<double> testResults;
    int numGoods = 0;
    for (int i = 0; i < input1.size(); i++) {
        std::vector<double> testInputs{static_cast<double>(input1[i]), static_cast<double>(input2[i])};
        nn.predict(testInputs, testResults);

        if (abs(testResults[0] - output[i]) < 0.01)
            numGoods++;
    }
    double percent = numGoods / static_cast<double>(input1.size()) * 100.0;
    printf("\nPercent predicted correctly: %f%%", percent);

    std::printf("\nTests completed successfully.\n");
}

void split(const std::string &s, const char delimiter, std::vector<int> &tokens) {
    std::stringstream ss(s);
    std::string token;
    while (!ss.eof()) {
        std::getline(ss, token, delimiter);
        tokens.push_back(stoi(token));
    }
}