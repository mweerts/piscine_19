/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 01:27:16 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/30 00:06:25 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INCLUDES_H
# define FT_INCLUDES_H

void	ft_putstr_error(char *str);
void	ft_putstr(char *str);
void	ft_puterror(char *argv, char *path, int errno, int is_offset);
void	ft_putheader(char *path);
int		ft_atoi(char *str);
int		ft_is_numeric(char *str);
#endif
