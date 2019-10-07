/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 01:25:56 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/30 00:07:04 by mweerts          ###   ########.fr       */
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
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putstr_error(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	ft_puterror(char *argv, char *path, int errno, int is_offset)
{
	if (is_offset == 0)
	{
		ft_putstr_error(basename(argv));
		ft_putstr_error(": ");
		ft_putstr_error(path);
		ft_putstr_error(": ");
		ft_putstr_error(strerror(errno));
		write(2, "\n", 1);
	}
	else
	{
		ft_putstr_error(basename(argv));
		ft_putstr_error(": illegal offset -- ");
		ft_putstr_error(path);
		write(2, "\n", 1);
	}
}

void	ft_putheader(char *path)
{
	write(1, "==> ", 4);
	ft_putstr(path);
	write(1, " <==\n", 5);
}

int		ft_is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
