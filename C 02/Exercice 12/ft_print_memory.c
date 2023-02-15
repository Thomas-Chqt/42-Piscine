/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:10:27 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/15 12:52:00 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);
void	ft_print_line(void *addr, unsigned int size);
char	*ft_dec_to_hex(unsigned long dec, int output_size);
void	ft_print_ascii(void *addr, unsigned int size);

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < (size / 16))
	{
		ft_print_line(addr + (i * 16), 16);
		i++;
	}
	if (size % 16 != 0)
		ft_print_line(addr + (i * 16), size % 16);
	return (addr);
}

void	ft_print_line(void *addr, unsigned int size)
{
	unsigned int	i;

	write(1, ft_dec_to_hex((unsigned long)addr, 8), 16);
	write(1, ": ", 2);
	i = 0;
	while (i < 16)
	{
		if (i < size)
			write(1, ft_dec_to_hex(*((char *)addr + i), 1), 2);
		else
			write(1, "  ", 2);
		i++;
		if (i < size)
			write(1, ft_dec_to_hex(*((char *)addr + i), 1), 2);
		else
			write(1, "  ", 2);
		write(1, " ", 1);
		i++;
	}
	ft_print_ascii(addr, size);
	write(1, "\n", 1);
}

char	*ft_dec_to_hex(unsigned long dec, int output_size)
{
	static char	hex[17];
	int			i;
	int			remainder;

	i = 0;
	while (i < output_size * 2)
	{
		hex[i] = '0';
		i++;
	}
	hex[output_size * 2] = '\0';
	i = (output_size * 2) - 1;
	while (dec > 0 && i >= 0)
	{
		remainder = dec % 16;
		if (remainder < 10)
			hex[i] = remainder + '0';
		else
			hex[i] = remainder - 10 + 'a';
		dec /= 16;
		i--;
	}
	return (hex);
}

void	ft_print_ascii(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (((char *)addr)[i] < ' ' || ((char *)addr)[i] > '~')
			write(1, ".", 1);
		else
			write(1, ((char *)addr) + i, 1);
		i++;
	}
}
