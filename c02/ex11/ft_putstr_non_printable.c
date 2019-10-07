/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:56:47 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/15 18:16:37 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_hex(int index, char *alphabet)
{
	int		i;
	int		final_number[10];
	char	c;

	i = 9;
	write(1, "\\", 1);
	if (index < 16)
		write(1, "0", 1);
	while (index > 15)
	{
		final_number[i] = index % 16;
		index = index / 16;
		i--;
	}
	final_number[i] = index;
	while (i < 10)
	{
		c = alphabet[final_number[i]];
		write(1, &c, 1);
		i++;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			put_hex(str[i], "0123456789abcdef");
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
