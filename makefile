# Compiler and compiler flags
CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -O2 -Wno-missing-braces

# Directories
SRC_DIR := src
INCLUDE_DIR := includes
LIB_DIR := lib
BIN_DIR := build

# Raylib Compilation flags
RAYLIB_FLAGS := -lraylib -lopengl32 -lgdi32 -lwinmm

# Source files and corresponding object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%.o, $(SRCS))

# Executable name
TARGET := worriorLeague

# Main target
all: $(BIN_DIR)/$(TARGET)
	@echo "$(SRCS) $(OBJS)"
	@$(BIN_DIR)/$(TARGET)

# Rule to compile object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Rule to link object files and create the executable
$(BIN_DIR)/$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ -L$(LIB_DIR) $(RAYLIB_FLAGS)

# Clean target
clean:
	rm -rf $(BIN_DIR)

# PHONY target to avoid conflicts with file named "clean"
.PHONY: clean
