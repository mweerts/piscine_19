# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mweerts <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/23 13:04:08 by mweerts           #+#    #+#              #
#    Updated: 2019/08/26 14:13:56 by mweerts          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH = ./srcs/
SRCS	=  ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c 
INCLUDES = ./includes/
OBJS = ${addprefix $(PATH), $(SRCS:.c=.o)}
NAME = libft.a

all: 	${NAME}

${PATH}%.o:${PATH}%.c
	gcc -Wall -Wextra -Werror -I ${INCLUDES} -c $< -o $@

${NAME}: ${OBJS}	
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}
clean:
		rm -rf ${OBJS}
fclean: clean	
		rm -rf ${NAME}
re:		fclean	all
