/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 01:25:56 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/29 19:41:23 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes.h"
#include <libgen.h>
#include <string.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puterror(char *argv, char *path, int errno)
{
	ft_putstr(basename(argv));
	ft_putstr(": ");
	ft_putstr(path);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	write(2, "\n", 1);
}
