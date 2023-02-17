/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:01:46 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/17 19:37:59 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_comb(void)
{
	char	comb[3];

	comb[0] = '0';
	while (comb[0] <= '7')
	{
		comb[1] = comb[0] + 1;
		while (comb[1] <= '8')
		{
			comb[2] = comb[1] + 1;
			while (comb[2] <= '9')
			{
				write(1, comb, 3);
				if (comb[0] != '7' || comb[1] != '8' || comb[2] != '9')
					write(1, ", ", 2);
				comb[2]++;
			}
			comb[1]++;
		}
		comb[0]++;
	}
}
