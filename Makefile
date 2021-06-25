NAME = libftprintf.a

SRC =	ft_printf.c\
		parser/ft_flags.c\
		parser/ft_parses.c\
		processor/ft_char_wr.c\
		processor/ft_hex_wr.c\
		processor/ft_int_wr.c\
		processor/ft_other_wr.c\
		processor/ft_perc_wr.c\
		processor/ft_cpointer_wr.c\
		processor/ft_str_wr.c\
		processor/ft_un_int_wr.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -c

CC = gcc

RM = rm -rf

INCLUDES = -I./includes

$(NAME): $(OBJ)
		$(MAKE) bonus ./libft
		cp libft/libft.a $(NAME)
		$(CC) $(FLAGS) $(INCLUDES) $(SRC)
		ar -rcs $(NAME) $(OBJ)

all : $(NAME)

clean:
		$(MAKE) clean ./libft
		$(RM) $(OBJ)

fclean: clean
		$(MAKE) fclean ./libft
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
