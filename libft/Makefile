NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include -I$(LIBFT_PATH)
AR = ar rcs

INCLUDE_PATH = ./include
LIBFT_PATH = ./libft
LIBFT_BONUS_PATH = ./libft_bonus
FT_PRINTF_PATH = ./ft_printf
GNL_PATH = ./gnl

LIBFT_SRCS = \
    ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
    ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
    ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c \
    ft_split.c ft_strchr.c ft_strrchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
    ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
    ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_putnbr_fd.c ft_strcmp.c \
    freetab.c ft_issign.c ft_iswhitespace.c \

LIBFT_BONUS_SRCS = \
    ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
    ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
    ft_lstmap.c \

FT_PRINTF_SRCS = \
    ft_hex_len.c ft_int_len.c ft_print_char.c ft_print_int.c ft_print_p.c ft_print_str.c \
    ft_print_u.c ft_print_x.c ft_printf.c ft_printux.c ft_print_percent.c ft_ui_len.c \

GNL_SRCS = \
	get_next_line.c get_next_line_utils.c \
	get_next_line_bonus.c get_next_line_utils_bonus.c \

SRCS = $(addprefix $(LIBFT_PATH)/, $(LIBFT_SRCS)) \
       $(addprefix $(LIBFT_BONUS_PATH)/, $(LIBFT_BONUS_SRCS)) \
       $(addprefix $(FT_PRINTF_PATH)/, $(FT_PRINTF_SRCS)) \
	   $(addprefix $(GNL_PATH)/, $(GNL_SRCS)) 

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
