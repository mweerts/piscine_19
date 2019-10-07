/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_to_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrooba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 09:11:22 by pstrooba          #+#    #+#             */
/*   Updated: 2019/08/25 17:05:13 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_str.h"
#include "nbr_to_index.h"

int		ft_hundreds(char *src, char *index, int n, int i)
{
	if (src[n] == 48)
		return (0);
	index[i++] = src[n];
	index[i++] = 32;
	index[i++] = 49;
	index[i++] = 48;
	index[i++] = 48;
	index[i] = 32;
	return (6);
}

int		ft_tens(char *src, char *index, int n, int i)
{
	if (src[n] == 48)
		return (0);
	if (src[n] == 49 && src[n + 1] != 48)
	{
		index[i] = src[n];
		return (1);
	}
	index[i++] = src[n];
	index[i++] = 48;
	index[i] = 32;
	return (3);
}

int		ft_units(char *src, char *index, int n, int i)
{
	if (src[n] == 48)
		return (0);
	index[i++] = src[n];
	index[i] = 32;
	return (2);
}

int		ft_thousand_rank(char *src, char *index, int n, int i)
{
	int s;

	s = 0;
	if ((ft_strlen(src) - n) / 3 == 3)
	{
		index[i++] = 49;
		while (++s < 10)
			index[i++] = 48;
		index[i] = 32;
	}
	if ((ft_strlen(src) - n) / 3 == 2)
	{
		index[i++] = 49;
		while (++s < 7)
			index[i++] = 48;
		index[i] = 32;
	}
	if ((ft_strlen(src) - n) / 3 == 1)
	{
		index[i++] = 49;
		while (++s < 4)
			index[i++] = 48;
		index[i] = 32;
	}
	return (s + 1);
}

char	*ft_nbr_to_index(char *src)
{
	char	*index;
	int		i;
	int		n;

	n = 0;
	i = 0;
	index = malloc(sizeof(char) * 69);
	if (ft_strlen(src) == 1)
		index[i++] = src[n++];
	while (src[n] > 47 && src[n] < 58)
	{
		if ((ft_strlen(src) - n) % 3 == 0)
			i += ft_hundreds(src, index, n++, i);
		if ((ft_strlen(src) - n) % 3 == 2)
			i += ft_tens(src, index, n++, i);
		if ((ft_strlen(src) - n) % 3 == 1)
			i += ft_units(src, index, n++, i);
		if (src[n - 1] != 48 || src[n - 2] != 48 || src[n - 3] != 48)
			i += ft_thousand_rank(src, index, n, i);
		else if (n == ft_strlen(src))
			i += 1;
	}
	index[i - 2] = '\0';
	return (index);
}
