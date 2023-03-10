/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:54:54 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/02 22:15:47 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

typedef int	(*t_func_ptr)(int, int);

int		ft_plus(int a, int b);
int		ft_minus(int a, int b);
int		ft_divide(int a, int b);
int		ft_multiply(int a, int b);
int		ft_modulo(int a, int b);

int		ft_do_op(int a, char op, int b);

int		ft_atoi(char *str);
void	ft_putnbr(int nb);

#endif