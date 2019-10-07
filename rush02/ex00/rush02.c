/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 17:49:57 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/25 20:07:26 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_split.h"
#include "ft_check.h"
#include "nbr_to_index.h"
#include "ft_dictionnaire.h"
#include <unistd.h>

int		main(int argc, char **argv)
{
	char	*dico;
	char	*nbr;
	char	*path;

	nbr = NULL;
	path = "numbers.dict";
	if (argc == 2)
		nbr = argv[1];
	else if (argc == 3)
	{
		path = argv[1];
		nbr = argv[2];
	}
	else
	{
		ft_putstr("Error\n");
		return (-1);
	}
	if ((dico = read_dictionnaire(path)) == NULL)
		return (-1);
	if (check_error(argc, nbr, dico) == 0)
		return (-1);
	print_words(dico, nbr);
	return (0);
}
