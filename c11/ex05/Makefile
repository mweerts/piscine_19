# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mweerts <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/27 12:35:00 by mweerts           #+#    #+#              #
#    Updated: 2019/08/27 20:32:44 by mweerts          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH = ./srcs/
SRCS = do_op.c ft_op.c ft_str.c
INCLUDES = ./includes/
OBJS = ${addprefix $(PATH), $(SRCS:.c=.o)}
NAME = do-op

all: $(NAME)

$(PATH)%.o: ${PATH}%.c
			gcc  -Wall -Wextra -Werror -I ${INCLUDES} -c $< -o $@
${NAME}: ${OBJS}
			gcc -o $(NAME) $(OBJS) 

clean:
			rm -rf ${OBJS}

fclean: clean
		rm -rf $(NAME)

re:	fclean all
