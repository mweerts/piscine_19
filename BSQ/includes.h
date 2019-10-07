/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:10:22 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/27 17:27:07 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

typedef	struct	s_header
{
	int		nb_ligne;
	char 	c_vide;
	char 	c_obstacle;
	char 	c_plein;
}t_header;
t_header	ft_read_header(char *path);
#endif
