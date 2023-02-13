/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:54:18 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/11 10:59:12 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdio.h>

#define MAX_MODULO 1000000000

void	ft_print_absolutnum(long nbr);
int		ft_get_start_modulo(long nbr);

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
	int		modulo;
	long	rest;
	char	new_char;

	modulo = ft_get_start_modulo(nbr);
	rest = nbr;
	while (modulo >= 1)
	{
		new_char = '0' + (rest / modulo);
		write(1, &new_char, 1);
		rest %= modulo;
		modulo /= 10;
	}
}

int	ft_get_start_modulo(long nbr)
{
	int		modulo;
	long	rest;

	modulo = MAX_MODULO;
	rest = nbr;
	while (modulo >= 1)
	{
		if (rest / modulo > 0)
			return (modulo);
		rest %= modulo;
		modulo /= 10;
	}
	return (0);
}
