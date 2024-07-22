# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17 -O2

# Linker flags
LDFLAGS = 

# Project name
TARGET = my_program

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Find all source files in the SRC_DIR
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Generate object file names from source files
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(BIN_DIR)/$(TARGET)

# Linking
$(BIN_DIR)/$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LDFLAGS)

# Compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create directories if they don't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)/$(TARGET)

# Phony targets
.PHONY: all clean
