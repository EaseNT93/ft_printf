NAME = libftprintf.a

SRC =	ft_printf.c\
		parser/ft_flags.c\
		parser/ft_parses.c\
		processor/ft_char_wr.c\
		processor/ft_hex_wr.c\
		processor/ft_int_wr.c\
		processor/ft_other_wr.c\
		processor/ft_perc_wr.c\
		processor/ft_pointer_wr.c\
		processor/ft_str_wr.c\
		processor/ft_un_int_wr.c

OBJ = $(SRC:.c=.o)

OBJO = 	ft_flags.o\
		ft_parses.o\
		ft_char_wr.o\
		ft_hex_wr.o\
		ft_int_wr.o\
		ft_other_wr.o\
		ft_perc_wr.o\
		ft_pointer_wr.o\
		ft_str_wr.o\
		ft_un_int_wr.o

CFLAGS = -Wall -Wextra -Werror -c

CC = gcc

RM = rm -rf

INCLUDES = -I./includes

$(NAME): $(OBJ)
		$(MAKE) bonus -C ./libft
		cp libft/libft.a $(NAME)
		$(CC) $(CFLAGS) $(INCLUDES) $(SRC)
		ar -rcs $(NAME) $(OBJ)

all : $(NAME)

clean:
		$(MAKE) clean -C ./libft
		$(RM) $(OBJO)
		$(RM) $(OBJ)

fclean: clean
		$(MAKE) fclean -C ./libft
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
