# Makefile for C++ project

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -g -Iinclude

# Linker flags (if needed)
LDFLAGS =

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Output binary
TARGET = c-l-tro

# Default target
all: $(TARGET)

# Link the final executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(LDFLAGS) -o $@ $^

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Rebuild the project
rebuild: clean all

.PHONY: all clean rebuild
