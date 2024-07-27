# Makefile for cub3D

# Program name
NAME := cub3D

# Compiler
CC := gcc

# Compiler flags
CFLAGS := -Wall -Wextra -Werror

# Directories
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include

LFT_DIR := libft
MLX_DIR := mlx_linux

# .c files
SRCS_PATTERN := "*.c"
SRCS := $(shell find $(SRC_DIR)/ -type f -name $(SRCS_PATTERN))

# .o files
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Include flags (-I flags)
INCFLAGS := $(addprefix -I,$(shell find . -type d -name "include" -exec find "{}" -type d ";"))
INCFLAGS += -I$(MLX_DIR)/

# Linker flags (-l and -L flags)
LDFLAGS := -L$(LFT_DIR)/ -L$(MLX_DIR)/
LDLIBS := -lft -lmlx_Linux -lXext -lX11 -lm -lz

# Default target: Build program
all: $(LFT_DIR)/libft.a $(NAME)

# Rule to build libft.a
$(LFT_DIR)/libft.a:
	@$(MAKE) -C $(LFT_DIR)

# Linking rule
$(NAME): $(OBJS)
	@$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

# Compilation rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

# Clean target: Removes .o files
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LFT_DIR) clean

# Full clean target: Removes .o files and program
fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LFT_DIR) fclean

# Rebuild default target: Cleans and rebuilds the entire program
re: fclean all

# Phony target
PHONY:
	all clean fclean re
