/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:54:18 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/17 19:18:54 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

#define MAX_MODULO 1000000000
#define MAX_LENGTH 10

void	ft_print_absolutnum(long nbr);

void	ft_putnbr(int nb)
{
	long	long_nb;

	long_nb = (long)nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		ft_print_absolutnum((long_nb * -1));
	}
	else
	{
		ft_print_absolutnum(long_nb);
	}
}

void	ft_print_absolutnum(long nbr)
{
	char str[MAX_LENGTH];
	int str_length;
	int i;
	int modulo;

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

