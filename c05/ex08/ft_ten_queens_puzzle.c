/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 19:39:29 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/27 12:47:57 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int tab[10][10])
{
	int		i;
	int		j;
	char	c;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			if (tab[i][j] != 0)
			{
				c = i + '0';
				write(1, &c, 1);
			}
			i++;
		}
		j++;
	}
	write(1, "\n", 1);
}

int		is_valid(int tab[10][10], int ligne, int col)
{
	int		i;
	int		j;

	j = 0;
	while (j < col)
	{
		if (tab[ligne][j++] != 0)
			return (0);
	}
	i = ligne;
	j = col;
	while (i >= 0 && j >= 0)
	{
		if (tab[i--][j--] != 0)
			return (0);
	}
	i = ligne;
	j = col;
	while (i <= 9 && j >= 0)
	{
		if (tab[i++][j--] != 0)
			return (0);
	}
	return (1);
}

int		solve(int tab[10][10], int col, int *count)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	if (col == 10)
	{
		*count += 1;
		print(tab);
		return (1);
	}
	while (i < 10)
	{
		if (is_valid(tab, i, col) == 1)
		{
			tab[i][col] = 1;
			res = solve(tab, col + 1, count);
			tab[i][col] = 0;
		}
		i++;
	}
	return (res);
}

int		ft_ten_queens_puzzle(void)
{
	int		tab[10][10];
	int		count;
	int		i;
	int		j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	count = 0;
	solve(tab, 0, &count);
	return (count);
}
