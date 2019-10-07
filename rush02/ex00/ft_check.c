/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:36:27 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/25 20:05:52 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check.h"
#include "ft_str.h"
#include "ft_split.h"

int		check_dictionnaire(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == '\n')
			i++;
		if (str[i] < 0 || str[i] > '9')
			return (0);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		while (str[i] == ' ')
			i++;
		if (str[i++] != ':')
			return (0);
		while (str[i] == ' ')
			i++;
		if (str[i] < 32 || str[i] == 127)
			return (0);
		while (str[i] >= 32 && str[i] < 127)
			i++;
		if (str[i++] != '\n')
			return (0);
	}
	return (1);
}

int		check_nbr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (i > 12)
		return (0);
	return (1);
}

int		check_error(int argc, char *nbr, char *dico)
{
	if (argc > 3 || argc == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (check_nbr(nbr) == 0 || check_dictionnaire(dico) == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}
