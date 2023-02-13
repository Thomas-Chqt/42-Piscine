/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:01:46 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/11 10:17:45 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

#define START_MODULO 100
#define NBR_SIZE 3

void	ft_print_num(int nbr);
int		need_print(int nbr);

void	ft_print_comb(void)
{
	int	i;

	i = 0;
	while (i <= 999)
	{
		if (need_print(i) == 1)
		{
			ft_print_num(i);
			if (i != 789)
				write(1, ", ", 2);
		}
		i++;
	}
}

void	ft_print_num(int nbr)
{
	int		modulo;
	int		rest;
	char	new_char;

	modulo = START_MODULO;
	rest = nbr;
	while (modulo >= 1)
	{
		new_char = '0' + (rest / modulo);
		write(1, &new_char, 1);
		rest %= modulo;
		modulo /= 10;
	}
}

int	need_print(int nbr)
{
	int	tab[NBR_SIZE];
	int	modulo;
	int	rest;
	int	nbr_digits;

	modulo = START_MODULO;
	rest = nbr;
	nbr_digits = 0;
	while (modulo >= 1)
	{
		tab[nbr_digits] = rest / modulo;
		rest %= modulo;
		modulo /= 10;
		if ((nbr_digits > 0) && (tab[nbr_digits] <= tab[nbr_digits - 1]))
			return (0);
		nbr_digits++;
	}
	return (1);
}
