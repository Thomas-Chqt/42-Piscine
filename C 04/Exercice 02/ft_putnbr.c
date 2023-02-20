/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:54:07 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/20 21:57:15 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

#define MAX_MODULO 1000000000
#define MAX_LENGTH 10


void	ft_putabsnbr(long nbr);

void	ft_putnbr(int nb)
{
	long	long_nb;

	long_nb = (long)nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		ft_putabsnbr((long_nb * -1));
	}
	else
	{
		ft_putabsnbr(long_nb);
	}
}

void	ft_putabsnbr(long nbr)
{
	char	str[MAX_LENGTH];
	int		str_length;
	int		i;
	int		modulo;

	str_length = 10;
	i = 0;
	modulo = MAX_MODULO;
	while (i < MAX_LENGTH)
	{
		str[i] = (nbr / modulo) + '0';
		nbr %= modulo;
		modulo /= 10;
		i++;
	}
	while (str[10 - str_length] == '0')
	{
		str_length--;
	}
	if (str_length == 0)
		str_length = 1;
	write(1, str + (10 - str_length), str_length);
}
