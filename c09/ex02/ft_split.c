/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 15:26:05 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/24 20:42:42 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_separator(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		nbr_mots(char *str, char *charset)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_separator(str[i], charset) == 1)
			i++;
		if (str[i] != '\0' && is_separator(str[i], charset) == 0)
		{
			count++;
			while (str[i] != '\0' && is_separator(str[i], charset) == 0)
				i++;
		}
	}
	return (count);
}

char	*word(char *str, char *charset)
{
	char	*mot;
	int		i;

	i = 0;
	while (str[i] != '\0' && is_separator(str[i], charset) == 0)
		i++;
	mot = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != '\0' && is_separator(str[i], charset) == 0)
	{
		mot[i] = str[i];
		i++;
	}
	mot[i] = '\0';
	return (mot);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		j;

	tab = malloc(sizeof(char*) * (nbr_mots(str, charset) + 1));
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_separator(str[i], charset) == 1)
			i++;
		if (str[i] != '\0' && is_separator(str[i], charset) == 0)
		{
			tab[j] = word(&str[i], charset);
			j++;
			while (str[i] != '\0' && is_separator(str[i], charset) == 0)
				i++;
		}
	}
	tab[nbr_mots(str, charset)] = NULL;
	return (tab);
}
