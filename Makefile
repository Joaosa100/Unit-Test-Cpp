# Makefile for a C++ project

# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -std=c++17 -Wall -Wextra

# Source directory
SRC_DIR := src

# Build directory
BUILD_DIR := build

# Target executable
TARGET := output

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp) \
tests/teste-avaliador.cpp

# Object files
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Default rule
all: $(BUILD_DIR) $(TARGET)

# Rule to create build directory
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean

#tips: 1)make 2)./output 3)make clean