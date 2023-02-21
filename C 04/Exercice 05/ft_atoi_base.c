/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:11:54 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/21 16:16:40 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_base(char *base);
int	ft_get_index(char c, char *base);
int	ft_strlen(char *str);
int	ft_pow(int nbr, int exp);

int	ft_atoi_base(char *str, char *base)
{
	int	nbr;
	int	i;
	int	len;

	nbr = 0;
	if (ft_check_base(base) != 0)
		return (0);
	len = 0;
	while (ft_get_index(str[len], base) >= 0)
		len++;
	i = 0;
	while (i < len)
	{
		nbr += ft_get_index(str[i], base)
			* ft_pow(ft_strlen(base), len - i - 1);
		i++;
	}
	return (nbr);
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

int	ft_get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_pow(int nbr, int exp)
{
	int	i;
	int	res;

	res = 1;
	i = 0;
	while (i < exp)
	{
		res *= nbr;
		i++;
	}
	return (res);
}
