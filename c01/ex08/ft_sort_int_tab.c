/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:52:28 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/10 23:35:22 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int index;
	int tmp;

	tmp = 0;
	index = 0;
	while (index < size - 1)
	{
		i = index + 1;
		while (i < size)
		{
			if (tab[i] < tab[index])
			{
				tmp = tab[i];
				tab[i] = tab[index];
				tab[index] = tmp;
			}
			i++;
		}
		index++;
	}
}
