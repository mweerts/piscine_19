/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:11:56 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/19 13:02:58 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int check_ligne(int tab[4][4], int input[16], int i);

void	write_int_tab(int size, int tab[size][size])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			c = tab[i][j] + '0';
			write(1, &c, 1);
			if (j != size - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	absent_colonne(int k, int tab[4][4], int j)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (tab[i][j] == k)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid(int tab[4][4], int input[16], int pos, int possibilities[24][4])
{
	int		i;
	int		j;
	int		k;

	if (pos == 16)
		return (1);
	i = pos / 4;
	j = pos % 4;
	if (tab[i][j] != 0)
		return (is_valid(tab, input, pos + 1, possibilities));
	k = 0;
	while (k < 24)
	{
		if (absent_colonne(possibilities[k][0], tab, 0) == 1 &&
		absent_colonne(possibilities[k][1], tab, 1) == 1 &&
		absent_colonne(possibilities[k][2], tab, 2) == 1 &&
		absent_colonne(possibilities[k][3], tab, 3) == 1)
		{
			tab[i][0] = possibilities[k][0];
			tab[i][1] = possibilities[k][1];
			tab[i][2] = possibilities[k][2];
			tab[i][3] = possibilities[k][3];
			if (check_ligne(tab, input, i) == 1)
			{
				if (is_valid(tab, input, pos + 1, possibilities) == 1)
					return (1);
			}
			else
			{
				tab[i][0] = 0;
				tab[i][1] = 0;
				tab[i][2] = 0;
				tab[i][3] = 0;
			}
		}
		k++;
	}
	tab[i][0] = 0;
	tab[i][1] = 0;
	tab[i][2] = 0;
	tab[i][3] = 0;
	return (0);
}

int	main(void)
{
	int 	tab[4][4] = {{0, 0, 0, 0},
						{0, 0, 0, 0},
						{0, 0, 0, 0},
						{0, 0, 0, 0}};
	int 	conditions[16] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};
	int 	possibilities[24][4] = {{4, 3, 2, 1},
								{4, 3, 1, 2},
								{4, 2, 1, 3},
								{4, 2, 3, 1},
								{4, 1, 2, 3},
								{4, 1, 3, 2},
								{3, 4, 1, 2},
								{3, 4, 2, 1},
								{3, 2, 4, 1},
								{3, 2, 1, 4},
								{3, 1, 2, 4},
								{3, 1, 4, 2},
								{2, 1, 3, 4},
								{2, 1, 4, 3},
								{2, 3, 1, 4},
								{2, 3, 4, 1},
								{2, 4, 1, 3},
								{2, 4, 3, 1},
								{1, 2, 3, 4},
								{1, 2, 4, 3},
								{1, 3, 4, 2},
								{1, 3, 2, 4},
								{1, 4, 2, 3},
								{1, 4, 3, 2}};

	if (is_valid(tab, conditions, 0, possibilities))
		write_int_tab(4, tab);
	else
		write(1, "Error\n", 6);
}
