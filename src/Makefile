CXX = g++
CXXFLAGS = -std=c++20 -g -Wall -Werror=vla -MMD
EXEC = main

SRC_DIRS := ./ ./enemies/ ./floors/  ./items/ ./players/  # Add your source folders here
OBJ_DIR := ./build

# Find all source files in the specified directories
SOURCES := $(wildcard $(addsuffix *.cc,$(SRC_DIRS)))

# Generate corresponding object file paths
OBJECTS := $(patsubst %.cc,$(OBJ_DIR)/%.o,$(notdir $(SOURCES)))

VPATH := $(SRC_DIRS)

# Rule to build the executable
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC)

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: %.cc
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

