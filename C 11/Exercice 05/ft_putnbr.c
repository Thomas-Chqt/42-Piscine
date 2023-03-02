/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:54:07 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/02 22:40:07 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putabnbr(long nb);

void	ft_putnbr(int nb)
{
	long	l_n;

	l_n = (long)nb;
	if (l_n < 0)
	{
		write(1, "-", 1);
	}
	ft_putabnbr(l_n);
}

void	ft_putabnbr(long nb)
{
	char	c;

	if ((nb / 10) > 0)
	{
		ft_putabnbr(nb / 10);
	}
	c = (nb % 10) + '0';
	write(1, &c, 1);
}