/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:50:55 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/30 00:08:48 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <libgen.h>

#include <stdio.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int		ft_size_file(char *argv, char *path)
{
	int		fd;
	int		ret;
	char	c;
	int		size;

	size = 0;
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		ft_puterror(argv, path, errno, 0);
		return (-1);
	}
	while ((ret = read(fd, &c, 1)) != 0)
	{
		if (ret < 0)
			break ;
		size++;
	}
	close(fd);
	return (size);
}

void	print_file(char *argv, char *path, int *tab, int *j)
{
	int		fd;
	int		ret;
	int		size;
	char	c;
	int		count;

	count = 0;
	size = ft_size_file(argv, path);
	if (size == -1)
		return ;
	if ((fd = open(path, O_RDONLY)) == -1)
		return ;
	if (*j != 3)
		write(1, "\n", 1);
	if (tab[1] == 0)
		ft_putheader(path);
	while ((ret = read(fd, &c, 1)) != 0)
	{
		if (ret < 0)
			break ;
		if (++count > size - tab[0])
			write(1, &c, 1);
	}
	*j = *j + 1;
	close(fd);
}

void	ft_stdin(char **argv)
{
	int		nb_bytes;
	char	buff[290000];
	int		count;
	int		i;
	char	c;

	count = 0;
	i = 1;
	nb_bytes = ft_atoi(argv[2]);
	while (read(0, &c, 1))
	{
		buff[count] = c;
		count++;
	}
	buff[count] = '\0';
	i = count - nb_bytes;
	while (buff[i])
	{
		write(1, &buff[i++], 1);
	}
}

int		main(int argc, char **argv)
{
	int i;
	int j;
	int tab[2];

	tab[1] = 0;
	i = 3;
	j = 3;
	if (argc >= 3 && ft_is_numeric(argv[2]) == 0)
	{
		ft_puterror(argv[0], argv[2], 0, 1);
		return (-1);
	}
	else if (argc == 3 && ft_is_numeric(argv[2]) == 1
			&& ft_strcmp(argv[1], "-c") == 0)
		ft_stdin(argv);
	if (argc < 4)
		return (0);
	if (argc == 4)
		tab[1] = 1;
	if (ft_strcmp(argv[1], "-c") != 0)
		return (-1);
	tab[0] = ft_atoi(argv[2]);
	while (i < argc)
		print_file(argv[0], argv[i++], tab, &j);
}
