# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mweerts <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/27 12:35:00 by mweerts           #+#    #+#              #
#    Updated: 2019/08/29 19:41:13 by mweerts          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH = ./srcs/
SRCS = ft_str.c ft_cat.c
INCLUDES = ./includes/
OBJS = ${addprefix $(PATH), $(SRCS:.c=.o)}
NAME = ft_cat

all: $(NAME)

$(PATH)%.o: ${PATH}%.c
			gcc -Wall -Wextra -Werror -I ${INCLUDES} -c $< -o $@
${NAME}: ${OBJS}
			gcc -o $(NAME) $(OBJS) 

clean:
			rm -rf ${OBJS}

fclean: clean
		rm -rf $(NAME)

re:	fclean all
