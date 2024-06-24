# Makefile for cub3D

# Program name
NAME := cub3D

# Directory paths
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
INCLUDES_DIR := includes

LIBFT_DIR := libft
MLX_DIR := mlx_linux

# Exclude files (relative to $(SRC_DIR))
# Use EXCLUDE_DIRS for directories to exclude (e.g., dir1 dir2)
# Use EXCLUDE_SRCS for specific files to exclude (e.g., dir1/file1.c)
EXCLUDE_DIRS :=
EXCLUDE_SRCS :=
EXCLUDE_FILES := $(addprefix $(SRC_DIR)/, $(addsuffix /*, $(EXCLUDE_DIRS))) \
				 $(addprefix $(SRC_DIR)/, $(EXCLUDE_SRCS))

# Source files
SRC_FILES := $(shell find $(SRC_DIR)/ -type f -name "*.c")
SRCS := $(filter-out $(EXCLUDE_FILES), $(SRC_FILES))

# Object files
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compiler settings
CC := gcc
CFLAGS := -MMD -MP -Wall -Werror -Wextra $(if $(W),-w)

# Include directories to search for header files
IDIRS := $(if $(wildcard $(INCLUDES_DIR)/*), $(addprefix -I, $(shell find $(INCLUDES_DIR)/ -type d)),)
IDIRS += $(if $(wildcard $(LIBFT_DIR)/$(INCLUDES_DIR)/*), $(addprefix -I, $(shell find $(LIBFT_DIR)/$(INCLUDES_DIR) -type d)))
IDIRS += -I$(MLX_DIR)/

# For debugging purposes, to see the include paths
# $(info Include paths: $(IDIRS))

# Linker flags and libraries
LDFLAGS := -L$(LIBFT_DIR)/ -L$(MLX_DIR)/
LDLIBS := -lft -lmlx_Linux -lXext -lX11 -lm -lz

# Default target
all: $(BIN_DIR)/$(NAME)

# Rule to build library
$(BIN_DIR)/$(NAME): $(OBJS) | $(BIN_DIR)
	$(CC) $^ $(LDFLAGS) $(LDLIBS) -o $@

# Pattern rule to compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IDIRS) -c $< -o $@

# Target to set W=1
w:
	$(MAKE) W=1

# Remove object directory
clean:
	rm -rf $(OBJ_DIR)

# Remove generated files
fclean: clean
	rm -rf $(BIN_DIR)

# Rebuild library
re: fclean all

# Create bin and obj directory if they don't exist
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# Phony targets
.PHONY: all w clean fclean re

# Include dependency files
-include $(OBJS:.o=.d)
