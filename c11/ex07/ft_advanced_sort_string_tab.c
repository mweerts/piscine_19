/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 12:48:36 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/28 22:47:11 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		ft_tab_size(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		start;
	int		end;
	int		size;

	size = ft_tab_size(tab);
	end = size;
	while (end > 0)
	{
		start = 0;
		while (start < size - 1)
		{
			if (cmp(tab[start], tab[start + 1]) > 0)
				ft_swap(&tab[start], &tab[start + 1]);
			start++;
		}
		end--;
	}
}
