/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 17:55:59 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/18 17:56:49 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	left(int tab[4][4], int input[16], int i)
{
	int k;
	int index;
	int count;

	k = 0;
	index = tab[i][k];
	count = 1;
	while (k < 3)
	{
		if (index < tab[i][k + 1])
		{
			count++;
			index = tab[i][k + 1];
		}
		k++;
	}
	if (count == input[i + 8])
		return (1);
	return (0);
}

int	right(int tab[4][4], int input[16], int i)
{
	int k;
	int index;
	int count;

	k = 3;
	index = tab[i][k];
	count = 1;
	while (k > 0)
	{
		if (index < tab[i][k - 1])
		{
			count++;
			index = tab[i][k - 1];
		}
		k--;
	}
	if (count == input[i + 12])
		return (1);
	return (0);
}

int	check_ligne(int tab[4][4], int input[16], int i)
{
	if (left(tab, input, i) == 1 && right(tab, input, i) == 1)
		return (1);
	else
		return (0);
}
