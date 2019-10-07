# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mweerts <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/27 12:35:00 by mweerts           #+#    #+#              #
#    Updated: 2019/08/28 01:17:46 by mweerts          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH = ./srcs/
SRCS = ft_display_file.c
INCLUDES = ./includes/
OBJS = ${addprefix $(PATH), $(SRCS:.c=.o)}
NAME = ft_display_file

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
