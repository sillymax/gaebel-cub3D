# Makefile for libft

# Library name
NAME := libft.a

# Directory paths
SRC_DIR := src
OBJ_DIR := obj
INCLUDES_DIR := includes

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
CFLAGS := -MMD -MP -Wall -Werror -Wextra $(if $(WARN),-w)

# Include directories to search for header files
IDIRS := $(addprefix -I, $(shell find $(INCLUDES_DIR)/ -type d))

# Linker flags and libraries
LDFLAGS :=
LDLIBS :=

# Default target
all: $(NAME)

# Rule to build library
$(NAME): $(OBJS)
	ar -rcs $@ $^

# Pattern rule to compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(IDIRS) $(LDFLAGS) -c $< $(LDLIBS) -o $@

# Remove object directory
clean:
	rm -rf $(OBJ_DIR)

# Remove generated files
fclean: clean
	rm -rf $(NAME)

# Rebuild library
re: fclean all

# Phony targets
.PHONY: all clean fclean re

# Include dependency files
-include $(OBJS:.o=.d)
