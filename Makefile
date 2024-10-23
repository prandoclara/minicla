# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: claprand <claprand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 16:22:57 by claprand          #+#    #+#              #
#    Updated: 2024/10/21 13:56:30 by claprand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
DEF_COLOR		= \033[0;39m
GREY			= \033[0;90m
RED				= \033[0;91m
GREEN			= \033[0;92m
YELLOW			= \033[0;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m
WHITE			= \033[0;97m
ORANGE			= \033[38;5;214m

NAME = minishell

CC = cc
INCLUDES = -I ./libft/include -I ./include
CFLAGS = -Wall -Wextra -Werror -g3 $(INCLUDES)
LFLAGS = -lreadline
MAKEFLAGS += --no-print-directory
VMINI	= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes \
         --suppressions=/home/claprand/Documents/minishell_git/minishell.sup \
         --track-fds=yes ./minishell


SRCS_DIR = ./srcs
OBJS_DIR = ./obj
SRC = 	main.c \
		builtins/env_builtin.c \
		builtins/pwd_builtin.c \
		builtins/echo_builtin.c \
		builtins/cd_builtin.c \
		builtins/utils.c \
		builtins/exit_builtin.c \
		builtins/export_builtin.c \
		builtins/export_no_args.c \
		builtins/unset_builtin.c \
		env/env.c \
		init/init_data.c \
		init/init_cmd.c \
		init/init_io.c \
		execution/execute_builtin.c \
		execution/execute_cmds.c \
		execution/parse_path.c \
		utils/free_or_close.c \
		utils/exit.c \
		redirections/infile_outfile.c \
		redirections/pipes.c \
		execution/execute.c \

		
SRCS = $(addprefix $(SRCS_DIR)/, $(SRC))
OBJ = $(SRC:.c=.o)	
OBJS = $(patsubst %(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

LIBFT_DIR		= libft/
LIBFT_NAME		= libft.a
LIBFT			= $(LIBFT_DIR)$(LIBFT_NAME)
	
all: $(NAME)

$(LIBFT):
	@echo "$(GREY)Compiling libft...$(DEF_COLOR)"
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(ORANGE)Compiling $(NAME) with objects:\n$(OBJS)$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "$(GREEN)$(NAME) has been created.$(DEF_COLOR)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@echo "$(ORANGE)Compiling $< to $@$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@echo "$(MAGENTA)Cleaning up...$(DEF_COLOR)"
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)Performing full clean...$(DEF_COLOR)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
	@echo "$(BLUE)Cleaned and rebuilt everything for minishell$(DEF_COLOR)"

rlleaks:		$(NAME)
				$(VMINI) ./minishell

.PHONY: all clean fclean re