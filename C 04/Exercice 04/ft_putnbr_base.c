/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:08:55 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/21 14:16:53 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

typedef unsigned char	t_uint8;

void	ft_putabnbr_base(unsigned int nbr, char *base);
int		ft_check_base(char *base);
int		ft_strlen(char *str);

void	ft_putnbr_base(int nbr, char *base)
{
	long	l_nbr;

	l_nbr = (long)nbr;
	if (ft_check_base(base) != 0)
		return ;
	if (l_nbr < 0)
	{
		write(1, "-", 1);
		l_nbr *= -1;
	}
	ft_putabnbr_base((unsigned int)l_nbr, base);
}

void	ft_putabnbr_base(unsigned int nbr, char *base)
{
	if ((nbr / ft_strlen(base)) > 0)
	{
		ft_putabnbr_base(nbr / ft_strlen(base), base);
	}
	write(1, &base[nbr % ft_strlen(base)], 1);
}

int	ft_check_base(char *base)
{
	int	i;
	int	y;

	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	i = 0;
	while (base[i])
	{
		if (base[i] == ' ' || (base[i] >= '\t' && base[i] <= '\r'))
			return (2);
		if (base[i] == '+' || base[i] == '-')
			return (3);
		y = i + 1;
		while (base[y])
		{
			if (base[i] == base[y])
				return (4);
			y++;
		}
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
