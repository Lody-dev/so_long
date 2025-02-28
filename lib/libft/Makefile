# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsarmien <dsarmien@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 18:34:57 by dsarmien          #+#    #+#              #
#    Updated: 2025/02/17 13:07:47 by dsarmien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Instructions
NAME	= libft.a
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -I $(INC_DIR)
AR		= ar rcs
MD		= mkdir -p
RM		= rm -f
PRINT	= echo

# Directories
BIN_DIR = bin
BLD_DIR = build
INC_DIR = inc
LIB_DIR = lib
OBJ_DIR	= $(BLD_DIR)/obj
SRC_DIR = src

# Main file
MAIN_DIR = main

# C Source Files
SRC_MAN	= $(SRC_DIR)/ft_ascii.c $(SRC_DIR)/ft_ascii_extra.c $(SRC_DIR)/ft_str_utils.c \
		  $(SRC_DIR)/ft_mem_setters.c $(SRC_DIR)/ft_mem_utils.c $(SRC_DIR)/ft_str_gen.c \
		  $(SRC_DIR)/ft_str_mod.c $(SRC_DIR)/ft_str_search.c $(SRC_DIR)/ft_split.c \
		  $(SRC_DIR)/ft_int2str.c $(SRC_DIR)/ft_fd_str.c $(SRC_DIR)/ft_fd_num.c
		  
SRC_BON = $(SRC_DIR)/ft_lst_mod.c $(SRC_DIR)/ft_lst_add.c $(SRC_DIR)/ft_lst_rem.c \
		  $(SRC_DIR)/ft_lst_stat.c

SRC_EXT = $(SRC_DIR)/ft_fd_utils.c $(SRC_DIR)/ft_printf.c $(SRC_DIR)/ft_printf_utils.c \
		  $(SRC_DIR)/get_next_line.c

# Object Files
OBJ_MAN	= $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_MAN:.c=.o)))
OBJ_BON	= $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_BON:.c=.o)))
OBJ_EXT	= $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_EXT:.c=.o)))

# ANSI Colors
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
CYAN	= \033[0;36m
WHITE	= \033[0;37m
RESET	= \033[0m

# Compiler Rules
all: $(LIB_DIR)/$(NAME)
		@$(PRINT) "$(WHITE)[$(GREEN)✔$(WHITE)] Static library '$(YELLOW)$(NAME)$(WHITE)' created."

$(LIB_DIR)/$(NAME): $(OBJ_MAN)
		@$(MD) $(LIB_DIR)
		@$(AR) $(LIB_DIR)/$(NAME) $(OBJ_MAN)
		@$(PRINT) "$(WHITE)[$(BLUE)^$(WHITE)] $(YELLOW)Mandatory$(WHITE) functions compiled."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@$(MD) $(OBJ_DIR)
		@$(CC) $(FLAGS) -c $< -o $@
		@$(PRINT) "$(WHITE)[$(BLUE)✦$(WHITE)] File $(CYAN)'$<'$(WHITE) compiled."

bonus: $(OBJ_MAN) $(OBJ_BON)
		@$(MD) $(LIB_DIR)
		@$(AR) $(LIB_DIR)/$(NAME) $(OBJ_MAN) $(OBJ_BON)
		@$(PRINT) "$(WHITE)[$(BLUE)^$(WHITE)] $(YELLOW)Mandatory$(WHITE) and $(YELLOW)Bonus$(WHITE) functions compiled."
		@$(PRINT) "$(WHITE)[$(GREEN)✔$(WHITE)] Static library '$(YELLOW)$(NAME)$(WHITE)' created."

full: $(OBJ_MAN) $(OBJ_BON) $(OBJ_EXT)
		@$(MD) $(LIB_DIR)
		@$(AR) $(LIB_DIR)/$(NAME) $(OBJ_MAN) $(OBJ_BON) $(OBJ_EXT)
		@$(PRINT) "$(WHITE)[$(BLUE)^$(WHITE)] $(YELLOW)All$(WHITE) functions compiled."
		@$(PRINT) "$(WHITE)[$(GREEN)✔$(WHITE)] Static library '$(YELLOW)$(NAME)$(WHITE)' created."

clean:
		@$(RM) -r $(OBJ_DIR)
		@$(RM) -r $(BLD_DIR)
		@$(RM) $(OBJ_MAN) $(OBJ_BON) $(OBJ_EXT)
		@$(PRINT) "$(WHITE)[$(RED)✘$(WHITE)] Object files and folder '$(CYAN)$(BLD_DIR)$(WHITE)' deleted."

fclean: clean
		@$(RM) -r $(BIN_DIR) $(LIB_DIR)
		@$(PRINT) "$(WHITE)[$(RED)✘$(WHITE)] Binaries and folder '$(CYAN)$(BIN_DIR)$(WHITE)' deleted."
		@$(RM) $(LIB_DIR)/$(NAME)
		@$(PRINT) "$(WHITE)[$(RED)✘$(WHITE)] File $(CYAN)'$(NAME)'$(WHITE) deleted."

re:		fclean full

# OWN INSTRUCTIONS TO COMPILE BINARIES

ft_printf: full
		@$(MD) $(BIN_DIR)
		@$(CC) $(FLAGS) $(MAIN_DIR)/main_ft_printf.c -L $(LIB_DIR) -l:$(NAME) -o $(BIN_DIR)/ft_printf
		@$(PRINT) "$(WHITE)[$(GREEN)✔$(WHITE)] Binary '$(YELLOW)ft_printf$(WHITE)' created."

gnl: full
		@$(MD) $(BIN_DIR)
		@$(CC) $(FLAGS) $(MAIN_DIR)/main_gnl.c -L $(LIB_DIR) -l:$(NAME) -o $(BIN_DIR)/gnl
		@$(PRINT) "$(WHITE)[$(GREEN)✔$(WHITE)] Binary '$(YELLOW)gnl$(WHITE)' created."

.PHONY: all bonus full clean fclean re