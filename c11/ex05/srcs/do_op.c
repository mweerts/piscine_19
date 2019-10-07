/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:47:53 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/27 14:47:54 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "includes.h"

void	fill_tab(t_ft_op *ft_op)
{
	ft_op[0] = ft_plus;
	ft_op[1] = ft_minus;
	ft_op[2] = ft_multiply;
	ft_op[3] = ft_divide;
	ft_op[4] = ft_modulo;
}

int		main(int argc, char **argv)
{
	int		i;
	char	*op;
	t_ft_op ft_op[5];
	char	*comp;

	fill_tab(ft_op);
	if (argc != 4)
		return (0);
	op = argv[2];
	if ((op[0] != '+' && op[0] != '-' && op[0] != '*' && op[0] != '/'
			&& op[0] != '%') || op[1] != '\0')
	{
		ft_putstr("0\n");
		return (0);
	}
	i = 0;
	comp = "+-*/%";
	while (i < 5)
	{
		if (op[0] == comp[i])
			ft_op[i](ft_atoi(argv[1]), ft_atoi(argv[3]));
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
