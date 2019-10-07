/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionnaire.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:49:30 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/25 17:42:48 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICTIONNAIRE_H
# define FT_DICTIONNAIRE_H

char	*read_dictionnaire(char *path);
void	print_word(char **tab_dico, char *nbr);
void	print_words(char *dico, char *nbr);
#endif
