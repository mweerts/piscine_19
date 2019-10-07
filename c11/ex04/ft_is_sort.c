/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 20:06:59 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/28 19:51:10 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int nsorted_croiss;
	int nsorted_decroiss;

	nsorted_croiss = 0;
	nsorted_decroiss = 0;
	i = 0;
	while (i + 1 < length)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			nsorted_croiss = 1;
		i++;
	}
	i = 0;
	while (i + 1 < length)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			nsorted_decroiss = 1;
		i++;
	}
	if (nsorted_croiss == 1 && nsorted_decroiss == 1)
		return (0);
	return (1);
}
