/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 23:09:08 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/26 23:55:43 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	char c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

int		ft_atoi(char *str)
{
	int nombre;
	int count_neg;
	int i;

	i = 0;
	nombre = 0;
	count_neg = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count_neg++;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nombre = nombre * 10 + (str[i] - 48);
		i++;
	}
	if ((count_neg % 2) == 1)
		nombre *= -1;
	return (nombre);
}
