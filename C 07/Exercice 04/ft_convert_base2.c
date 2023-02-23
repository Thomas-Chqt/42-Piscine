/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:58:02 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/23 15:45:14 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_setabnbr_base(unsigned int nbr, char *base,
			char **str_to_set, int *str_c)
{
	if ((nbr / ft_strlen(base)) > 0)
	{
		ft_setabnbr_base(nbr / ft_strlen(base), base, str_to_set, str_c);
	}
	(*str_to_set)[*str_c] = base[nbr % ft_strlen(base)];
	(*str_c)++;
}

int	ft_recursive_power(int nb, int power)
{
	if (nb == 0 && power == 0)
		return (1);
	if (power > 0)
	{
		return (nb * ft_recursive_power(nb, power - 1));
	}
	if (power < 0)
	{
		return (0);
	}
	return (1);
}
