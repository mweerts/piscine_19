/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:31:09 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/26 17:40:34 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *ret;

	i = 0;
	ret = malloc(sizeof(int) * length);
	if (tab == NULL)
		return (NULL);
	while (i < length)
	{
		ret[i] = (*f)(tab[i]);
		i++;
	}
	return (ret);
}
