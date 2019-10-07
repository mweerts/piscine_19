/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:32:30 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/21 11:49:55 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt_extended(int nb)
{
	int	max;

	max = 1;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	if (nb > 2147395600)
		return (46340);
	while (nb > max * max)
		max++;
	if (nb == max * max)
		return (max);
	else
		return (max - 1);
}

int	ft_is_prime(int nb)
{
	int i;

	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	i = 3;
	while (i <= ft_sqrt_extended(nb))
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (nb % 2 == 0)
		nb++;
	while (ft_is_prime(nb) == 0)
	{
		nb += 2;
	}
	return (nb);
}
