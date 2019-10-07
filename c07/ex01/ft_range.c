/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:49:03 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/20 23:26:11 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *pt;
	int size_tab;
	int i;

	i = 0;
	size_tab = max - min;
	if (min >= max)
		return (NULL);
	pt = malloc(sizeof(int) * size_tab);
	if (pt == NULL)
		return (NULL);
	while (i < size_tab)
	{
		pt[i] = min;
		i++;
		min++;
	}
	return (pt);
}
