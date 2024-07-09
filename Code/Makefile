# Makefile for C++ project

# Compiler and compiler flags
CC := g++
CFLAGS := -Wall -Wextra -std=c++17
LDFLAGS :=

# Directories
SRC_DIR := src
INC_DIR := inc
BUILD_DIR := bin

# Source files and object files
SRC_FILES := $(wildcard $(SRC_DIR)/**/*.cpp) $(wildcard $(SRC_DIR)/*.cpp)
INC_FILES := $(wildcard $(INC_DIR)/**/*.h) $(wildcard $(INC_DIR)/*.h)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Include directories
INC_DIRS := $(sort $(dir $(INC_FILES)))
CFLAGS += $(addprefix -I,$(INC_DIRS))

# Executable name
EXECUTABLE := $(BUILD_DIR)/my_program

# Main target: Build the executable and run the program
all: $(EXECUTABLE)
	@echo [MAKEFILE] Run...
	@./$(EXECUTABLE) #### 2> /dev/null  # Redirect stderr to /dev/null

$(EXECUTABLE): $(OBJ_FILES)
	@echo [MAKEFILE] Build...
	@$(CC) $(OBJ_FILES) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo [MAKEFILE] Compile...
	@$(CC) $(CFLAGS) -c $< -o $@

# Rule to build directories for object files
$(BUILD_DIR)/%.o:
	@mkdir -p $(dir $@)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)
