/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:47:22 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/11 10:47:29 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_nbr(int nbr);

void	ft_print_comb2(void)
{
	int	array[2];

	array[0] = 0;
	while (array[0] <= 99)
	{
		array[1] = array[0] + 1;
		while (array[1] <= 99)
		{
			print_nbr(array[0]);
			write(1, " ", 1);
			print_nbr(array[1]);
			if (array[0] == 98 && array[1] == 99)
				break ;
			write(1, ", ", 2);
			array[1]++;
		}
		array[0]++;
	}
}

void	print_nbr(int nbr)
{
	char	str[2];

	str[0] = '0' + nbr / 10;
	str[1] = '0' + (nbr % 10) / 1;
	write(1, str, 2);
}
