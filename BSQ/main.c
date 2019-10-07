/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 11:41:57 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/27 17:37:35 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "includes.h"

void	ft_putstr (char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}


int main()
{
	t_header header;
	char *tab[10];
	header = ft_read_header("map");	

	printf("Vide : %c\nObstacle : %c\nPlein : %c\nNb ligne : %d\n", header.c_vide, header.c_obstacle, header.c_plein, header.nb_ligne);
}
