/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 10:31:39 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/10 13:52:25 by sjanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);

void	rush(int x, int y)
{
	int col;
	int ln;

	ln = 0;
	while (ln < y)
	{
		col = 0;
		while (col < x)
		{
			if ((col == 0 || col == x - 1) && (ln == 0 || ln == y - 1))
				ft_putchar('o');
			else if ((col != 0 || col != x - 1) && (ln == 0 || ln == y - 1))
				ft_putchar('-');
			else if ((col == 0 || col == x - 1) && (ln != 0 || ln != y - 1))
				ft_putchar('|');
			else
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		ln++;
	}
}
