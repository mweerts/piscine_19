/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 21:00:15 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/29 23:07:24 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

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

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buff;

	if (argc != 2)
	{
		if (argc < 2)
			ft_putstr_error("File name missing.\n");
		if (argc > 2)
			ft_putstr_error("Too many arguments.\n");
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr_error("Cannot read file.\n");
		return (-1);
	}
	while ((ret = read(fd, &buff, 1)) != 0)
		write(1, &buff, 1);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
