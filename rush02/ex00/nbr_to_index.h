/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_to_index.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 17:06:10 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/25 17:08:51 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NBR_TO_INDEX_H
# define NBR_TO_INDEX_H

int		ft_hundreds(char *src, char *index, int n, int i);
int		ft_tens(char *src, char *index, int n, int i);
int		ft_units(char *src, char *index, int n, int i);
int		ft_thousand_rank(char *src, char *index, int n, int i);
char	*ft_nbr_to_index(char *src);
#endif
