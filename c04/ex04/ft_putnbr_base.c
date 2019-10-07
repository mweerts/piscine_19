/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 01:43:46 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/14 15:21:47 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		check(char *base)
{
	int i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 33 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned	int	len_base;
	int				final_number[50];
	int				i;
	unsigned	int	nombre;

	i = 49;
	len_base = ft_strlen(base);
	if (check(base) == 0)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nombre = -nbr;
	}
	else
		nombre = nbr;
	while (nombre > len_base - 1)
	{
		final_number[i--] = nombre % len_base;
		nombre = nombre / len_base;
	}
	final_number[i] = nombre;
	while (i < 50)
		write(1, &base[final_number[i++]], 1);
}
