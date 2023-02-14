/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:21:25 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/15 00:13:05 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr_non_printable(char *str);
char*	ft_dec_to_hex(unsigned char decimal) ;

void	ft_putstr_non_printable(char *str)
{
		unsigned long long	i;

		i = 0;
		while (str[i] != '\0')
		{
			if (str[i] < ' ' || str[i] > '~')
			{
				write(1, "\\", 1);
				write(1, ft_dec_to_hex(*((unsigned char*)str + i)), 2);
			}
			else
			{
				write(1, str + i, 1);
			}
			i++;
		}
}

char* ft_dec_to_hex(unsigned char decimal) 
{
	static char hexa[3];

	hexa[0] = decimal / 16;
	hexa[1] = decimal % 16;

	for (int i = 0; i <= 1; i++)
	{
		if (hexa[i] < 10) 
		{
			hexa[i] += 48;
		}
		else 
		{
			hexa[i] += (55 + 32);
		}
	}
	hexa[2] = '\0';
	return hexa;
}