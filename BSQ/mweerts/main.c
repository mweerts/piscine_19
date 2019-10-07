/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 21:03:23 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/28 00:27:35 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int ft_length_line(char *path);

typedef struct s_header
{
	int nb_row;
	char c_vide;
	char c_obstacle;
	char c_plein;
}t_header;

char	**ft_init_tab(char *path, t_header header)
{
	char **tab;
	int i;
	int j;
	int fd;
	int ret;
	int length_line;
	char c;

	
	length_line = ft_length_line(path);
	tab = malloc(sizeof(char*) * header.nb_row);
	if (tab == NULL)
		return NULL;
	if((fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	while ((ret = read(fd, &c, 1)) != 0)
	{
		if (c == '\n')
			break;
	}
	while (i < header.nb_row)
	{
		tab[i] = malloc(sizeof(char) * (length_line + 1));
		if (tab[i] == NULL)
			return (NULL);
		j = 0;
		while ((ret = read(fd, &c, 1)) != 0)
		{
			tab[i][j] = c;
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	return (tab);
}

int		ft_length_line(char *path)
{	
	int count;
	int ret;
	int fd;
	char c;
	
	count = 0;
	if((fd = open(path, O_RDONLY)) == -1)
		return (-1);
	while ((ret = read(fd, &c, 1)) != 0)
	{
		if (c == '\n')
			break;
	}
	while ((ret = read(fd, &c, 1)) != 0)
	{
		if (c != '\n')
			count++;
		else if (c == '\n')
			return (count);
	}
	close(fd);
	return (-1);	
}

int main()
{
	t_header header;

	header.nb_row = 10;
	header.c_vide = '.';
	header.c_obstacle = 'o';
	
	int i = 0;
	char **tab = ft_init_tab("map", header);
	while (i < header.nb_row)
	{
		printf("%s", tab[i]);
	}

}
