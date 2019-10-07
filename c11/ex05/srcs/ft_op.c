/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 23:07:30 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/27 13:30:08 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	ft_plus(int a, int b)
{
	int i;

	i = a + b;
	ft_putnbr(i);
}

void	ft_minus(int a, int b)
{
	int i;

	i = a - b;
	ft_putnbr(i);
}

void	ft_divide(int a, int b)
{
	int i;

	if (b == 0)
	{
		ft_putstr("Stop : division by zero");
		return ;
	}
	i = a / b;
	ft_putnbr(i);
}

void	ft_multiply(int a, int b)
{
	int i;

	i = a * b;
	ft_putnbr(i);
}

void	ft_modulo(int a, int b)
{
	int i;

	if (b == 0)
	{
		ft_putstr("Stop : modulo by zero");
		return ;
	}
	i = a % b;
	ft_putnbr(i);
}
