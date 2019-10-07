/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjanssen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 08:49:32 by sjanssen          #+#    #+#             */
/*   Updated: 2019/08/11 18:46:39 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	write_pattern(int i, int j, int x, int y)
{
	if (i == 0 && j == 0)
		ft_putchar('/');
	else if ((i == y - 1 && j == x - 1) && x > 1 && y > 1)
		ft_putchar('/');
	else if (i == y - 1 && j == 0)
		ft_putchar('\\');
	else if (j == x - 1 && (i == 0 || i == y - 1))
		ft_putchar('\\');
	else if ((i == 0 || i == y - 1) && (j != 0 && j != x - 1))
		ft_putchar('*');
	else if ((j == 0 || j == x - 1) && (i != 0 && i != y - 1))
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			write_pattern(i, j, x, y);
			++j;
		}
		++i;
		ft_putchar('\n');
	}
}
