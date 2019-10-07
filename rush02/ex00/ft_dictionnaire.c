/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionnaire.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:49:04 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/25 18:18:50 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dictionnaire.h"
#include "ft_str.h"
#include "ft_split.h"
#include "nbr_to_index.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

char	*read_dictionnaire(char *path)
{
	int		fd;
	int		ret;
	char	*buff;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		ft_putstr("Dict Error\n");
		return (NULL);
	}
	ret = read(fd, buff, BUFFER_SIZE);
	buff[ret] = '\0';
	if (close(fd) == -1)
	{
		ft_putstr("Dict Error\n");
		return (NULL);
	}
	return (buff);
}

void	print_word(char **tab_dico, char *nbr)
{
	int i;

	i = 0;
	while (tab_dico[i] != NULL)
	{
		if (ft_strcmp(tab_dico[i], nbr) == 0)
			ft_putstr(tab_dico[i + 1]);
		i++;
	}
}

void	print_words(char *dico, char *nbr)
{
	int		i;
	char	**tab_dico;
	char	**tab_nbr;
	char	*index;

	i = 0;
	tab_dico = ft_split(dico, ": \n");
	index = ft_nbr_to_index(nbr);
	tab_nbr = ft_split(index, " ");
	free(index);
	while (tab_nbr[i] != NULL)
	{
		print_word(tab_dico, tab_nbr[i]);
		if (tab_nbr[i + 1] != NULL)
			write(1, " ", 1);
		else if (tab_nbr[i + 1] == NULL)
			write(1, "\n", 1);
		i++;
	}
	free(tab_dico);
	free(tab_nbr);
}
