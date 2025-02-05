# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++14 -Wall -I../headers

# Source files
SRCS = src/main.cpp src/neuron.cpp src/matrix.cpp src/neuralnet.cpp src/layer.cpp src/matrixMultiply.cpp src/matrixToVector.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = neuralNetwork

# Default target
all: $(EXEC)

# Link object files to create executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets
.PHONY: all clean
