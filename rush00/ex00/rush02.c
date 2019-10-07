/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjanssen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 08:49:32 by sjanssen          #+#    #+#             */
/*   Updated: 2019/08/10 13:59:53 by sjanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char a);

void		rush(int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (i == 0 && (j == x - 1 || j == 0))
				ft_putchar('A');
			else if (i == y - 1 && (j == 0 || j == x - 1))
				ft_putchar('C');
			else if ((i == 0 || i == y - 1) && (j != 0 && j != x - 1))
				ft_putchar('B');
			else if ((j == 0 || j == x - 1) && (i != 0 && i != y - 1))
				ft_putchar('B');
			else
				ft_putchar(' ');
			++j;
		}
		++i;
		ft_putchar('\n');
	}
}
