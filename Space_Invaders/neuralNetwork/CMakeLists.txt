cmake_minimum_required(VERSION 3.0)
project(neuralNetwork)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# Add source files
set(SOURCES
    src/main.cpp
    src/neuron.cpp
    src/layer.cpp
    src/train.cpp
    src/matrix.cpp
    src/neuralnet.cpp
    src/matrixMultiply.cpp
    src/matrixToVector.cpp
)
# Add executable
add_executable(
    neuralNetwork ${SOURCES}
)