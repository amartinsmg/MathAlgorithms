# =============================================================================
# mathlib — Makefile
# =============================================================================

CC      := gcc
CXX     := g++
CFLAGS  := -Wall -Wextra -O2 -fPIC
CXXFLAGS := -Wall -Wextra -O2 -fPIC -std=c++17

INCLUDE_FLAGS := -Iinclude

# -----------------------------------------------------------------------------
# Directories
# -----------------------------------------------------------------------------

SRC_DIR   := src
OBJ_DIR   := build
LIB_DIR   := lib
TEST_DIR  := tests
DEBUG_DIR := debug

# -----------------------------------------------------------------------------
# Sources and objects
# -----------------------------------------------------------------------------

C_SRCS   := $(wildcard $(SRC_DIR)/math/*.c) $(wildcard $(SRC_DIR)/utils/*.c)
C_OBJS   := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(C_SRCS))

# -----------------------------------------------------------------------------
# Targets
# -----------------------------------------------------------------------------

LIB_SO     := $(LIB_DIR)/libmath.so
TEST_C     := $(DEBUG_DIR)/test_c
TEST_CPP   := $(DEBUG_DIR)/test_cpp

# -----------------------------------------------------------------------------
# Default target
# -----------------------------------------------------------------------------

.PHONY: all
all: $(LIB_SO)

# -----------------------------------------------------------------------------
# Shared library
# -----------------------------------------------------------------------------

$(LIB_SO): $(C_OBJS) | $(LIB_DIR)
	$(CC) -shared -o $@ $^

# -----------------------------------------------------------------------------
# C objects
# -----------------------------------------------------------------------------

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

# -----------------------------------------------------------------------------
# Tests
# -----------------------------------------------------------------------------

.PHONY: test
test: $(TEST_C) $(TEST_CPP)

$(TEST_C): $(TEST_DIR)/test_c.c $(LIB_SO) | $(DEBUG_DIR)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -o $@ $< -L$(LIB_DIR) -lmath -lm

$(TEST_CPP): $(TEST_DIR)/test_cpp.cpp $(LIB_SO) | $(DEBUG_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE_FLAGS) -o $@ $< -L$(LIB_DIR) -lmath -lm

# -----------------------------------------------------------------------------
# Run tests
# -----------------------------------------------------------------------------

.PHONY: run-test-c run-test-cpp run-tests
run-test-c: $(TEST_C)
	LD_LIBRARY_PATH=$(LIB_DIR) ./$(TEST_C)

run-test-cpp: $(TEST_CPP)
	LD_LIBRARY_PATH=$(LIB_DIR) ./$(TEST_CPP)

run-tests: run-test-c run-test-cpp

# -----------------------------------------------------------------------------
# Directory creation (order-only prerequisites)
# -----------------------------------------------------------------------------

$(OBJ_DIR) $(LIB_DIR) $(DEBUG_DIR):
	mkdir -p $@

# -----------------------------------------------------------------------------
# Clean
# -----------------------------------------------------------------------------

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR) $(DEBUG_DIR)

# -----------------------------------------------------------------------------
# Phony help
# -----------------------------------------------------------------------------

.PHONY: help
help:
	@echo "Targets:"
	@echo "  all           Build the shared library (default)"
	@echo "  test          Build the test binaries"
	@echo "  run-tests     Build and run both tests"
	@echo "  run-test-c    Build and run the C test"
	@echo "  run-test-cpp  Build and run the C++ test"
	@echo "  clean         Remove all build artifacts"