/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 23:27:40 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/21 19:32:16 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int size_tab;
	int i;
	int *dest;

	i = 0;
	size_tab = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	dest = malloc(sizeof(int*) * size_tab);
	if (dest == NULL)
	{
		*range = NULL;
		return (-1);
	}
	while (i < size_tab)
	{
		dest[i] = min;
		i++;
		min++;
	}
	*range = dest;
	return (size_tab);
}
