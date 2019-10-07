/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:13:25 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/27 21:00:49 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "includes.h"

int		ft_open_file()
{
	return(0);
}

int	ft_atoi(char *str, int i)
{
	int j;
	int nbr;

	nbr = 0;
	j = 0;
	while(str[j] != '\0' && str[j] >= '0' && str[j] <= '9' && j < i)
	{
		nbr = nbr * 10 + (str[j] - 48);
		j++;
	}
	return (nbr);
}

t_header	ft_read_header(char *path)
{
	int fd;
	int ret;
	char *buff;
	int size_buff;
	int i;
	t_header header;
	char tmp[1000];

	i = 0;
	size_buff = 1000;
	buff = malloc(sizeof(char) * size_buff);
	if ((fd = open(path, O_RDONLY)) == -1)
		return header;
	ret = read(fd, buff, size_buff);
	buff[ret] = '\0';
	while (buff[i] != '\n')
	{
		tmp[i] = buff[i];
		i++;
	}
	tmp[i] = '\0';
	i -= 1;
	header.c_plein = tmp[i--];
	header.c_obstacle = tmp[i--];
	header.c_vide = tmp[i];
	header.nb_ligne = ft_atoi(tmp, i);
	return (header);
}

char	**ft_new_tab(t_header header)
{
	char **tab;

	tab = (char**)malloc(header.nb_ligne * sizeof(char*));
	if (tab == NULL)
		return (NULL);
	return (tab);
}

char 	*ft_init(char *path)
{
	int fd;
	int ret;
	char *buff;


}
