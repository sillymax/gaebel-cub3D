# Makefile for libft

# Library name
NAME := libft.a

# Compiler
CC := cc

# Compiler flags
CFLAGS := -Wall -Wextra -Werror

# Directories
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include

# .c files
SRCS_PATTERN := "*.c"
SRCS := $(shell find $(SRC_DIR)/ -type f -name $(SRCS_PATTERN))

# .o files
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Include flags (-I flags)
INCFLAGS := $(addprefix -I,$(shell find . -type d -name "include" -exec find "{}" -type d ";"))
INCFLAGS += -I$(MLX_DIR)/

# Linker flags (-l and -L flags)
# LDFLAGS :=
# LDLIBS :=

# Default target: Build library
all: $(NAME)

# Archive rule
$(NAME): $(OBJS)
	@ar -rcs $@ $^

# Compilation rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

# Clean target: Removes .o files
clean:
	@rm -rf $(OBJ_DIR)

# Full clean target: Removes .o files and program
fclean: clean
	@rm -rf $(NAME)

# Rebuild default target: Cleans and rebuilds the entire program
re: fclean all

# Phony target
PHONY:
	all clean fclean re
