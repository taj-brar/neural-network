cmake_minimum_required(VERSION 3.27)
project(neural_network)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(neural_network
        src/NeuralNetwork.cpp
        src/NeuralNetwork.h
        src/Layer.cpp
        src/Layer.h
        test.cpp
        src/Neuron.cpp
        src/Neuron.h)
