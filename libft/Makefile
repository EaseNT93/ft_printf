# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpants <dpants@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 01:28:00 by dpants            #+#    #+#              #
#    Updated: 2021/04/21 01:28:00 by dpants           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_bzero.c\
	ft_memccpy.c\
	ft_memcpy.c\
	ft_strchr.c\
	ft_strlen.c\
	ft_strrchr.c\
	ft_memset.c\
	ft_memcmp.c\
	ft_memchr.c\
	ft_memmove.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_strnstr.c\
	ft_strncmp.c\
	ft_atoi.c\
	ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_split.c

SRC_B = ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c

OBJ = ${SRC:.c=.o}

OBJ_B = ${SRC_B:.c=.o}

CFLAGS = -Wall -Wextra -Werror -c

CC = gcc

RM = rm -f

all: $(NAME)

$(NAME): 
		$(CC) $(CFLAGS) $(SRC)
		ar rcs $(NAME) $(OBJ)

bonus: 
		$(CC) $(CFLAGS) $(SRC) $(SRC_B)
		ar rcs $(NAME) $(OBJ) $(OBJ_B)

so:
	$(CC) -fPIC $(CFLAGS) $(SRC) $(SRC_B)
	gcc -shared -o libft.so $(OBJ) $(OBJ_B) 

norm: 
	norminette ${SRC} ${SRC_B} *.h

clean:
		${RM} ${OBJ} ${OBJ_B} 

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
