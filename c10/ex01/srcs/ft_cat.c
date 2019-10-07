/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 01:24:31 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/29 19:39:53 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "includes.h"
#include <errno.h>
#include <libgen.h>

int		ft_read(int i, int fd, char **argv)
{
	int		ret;
	char	c;

	ret = 0;
	while ((ret = read(fd, &c, 1)) != 0)
	{
		if (ret == -1)
		{
			ft_puterror(argv[0], argv[i], errno);
			break ;
		}
		ft_putchar(c);
	}
	if (close(fd) == -1)
		return (-1);
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	c;

	i = 1;
	if (argc == 1)
	{
		while ((read(0, &c, 1) != 0))
			write(1, &c, 1);
	}
	while (i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) < 0)
			ft_puterror(argv[0], argv[i], errno);
		else
		{
			if (ft_read(i, fd, argv) == -1)
				ft_puterror(argv[0], argv[i], errno);
		}
		i++;
	}
	return (0);
}
