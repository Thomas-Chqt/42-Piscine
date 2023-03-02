/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 10:57:27 by pichen            #+#    #+#             */
/*   Updated: 2023/02/26 22:58:45 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_convert_num.h"

int	count_len_thou(int num, int len)
{
	if (num == 0)
		len += 0;
	else if (num <= 20 || (num % 10 == 0 && num / 100 == 0))
		len += 1;
	else if (num % 100 == 0 || (num > 20 && num < 100))
		len += 2;
	else if (num % 100 <= 20 || num % 10 == 0)
		len += 3;
	else
		len += 4;
	return (len);
}

int	count_len(unsigned int num)
{
	int	len;
	int	i;
	int	cp_num;

	len = 0;
	i = -1;
	cp_num = num;
	if (num == 0)
		return (1);
	while (cp_num > 0)
	{
		num = cp_num % 1000;
		cp_num = cp_num / 1000;
		len = count_len_thou(num, len);
		i++;
	}
	return (len + i);
}

int	if_num_less_thou(unsigned int *a, unsigned int num, int i)
{
	if (num > 99)
	{
		a[i++] = num / 100;
		a[i++] = 100;
		num = num % 100;
	}
	if (num < 100)
	{
		if (num == 0)
			return (21);
		if ((num < 20 || (num % 10 == 0)))
		{
			a[i++] = num;
		}
		else if (num != 0)
		{
			a[i++] = num / 10 * 10;
			a[i++] = num % 10;
		}
	}
	return (i);
}

void	put_thou(unsigned int *a, int g_count, int i)
{
	int	k;
	int	thou;

	k = 1;
	thou = 1;
	while (k++ <= g_count + 1)
		thou *= 1000;
	a[i++] = thou;
}

unsigned int	*ft_convert_num_int(unsigned int *a,
	unsigned int num, int g_count, int i)
{
	if (num == 0)
		a[i++] = 0;
	if (num >= 1000)
		ft_convert_num_int(a, num / 1000, g_count + 1, i);
	else if (num < 1000)
	{	
		i = if_num_less_thou(a, num, i);
		if (g_count-- > 0)
			put_thou(a, g_count, i);
	}
	if (num >= 1000 && num % 1000 != 0)
	{
		while (a[i] != 21)
			i++;
		ft_convert_num_int(a, num % 1000, g_count, i);
	}
	return (a);
}
