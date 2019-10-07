/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 23:28:37 by mweerts           #+#    #+#             */
/*   Updated: 2019/08/27 14:34:02 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
void	ft_plus(int a, int b);
void	ft_minus(int a, int b);
void	ft_divide(int a, int b);
void	ft_multiply(int a, int b);
void	ft_modulo(int a, int b);
typedef	void	(*t_ft_op)(int a, int b);

#endif
