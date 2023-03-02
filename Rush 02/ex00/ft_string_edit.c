/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_edit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:23:42 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/26 23:38:42 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_normalise_str(char **str)
{
	char	*normalized_str;
	ssize_t	i;
	ssize_t	len;

	i = 0;
	while (ft_is_removeable((*str)[i]) && (*str)[i] != '\0')
		i++;
	len = (ft_strlen((*str)) - i);
	while (len >= 0 && ft_is_removeable((*str)[i + (len - 1)]))
		len--;
	normalized_str = ft_strdupl((*str) + i, len);
	if (normalized_str == NULL)
		return (1);
	free((*str));
	(*str) = normalized_str;
	return (0);
}

ssize_t	ft_atoi(char *str)
{
	int				signe;
	unsigned int	nbr;
	int				i;

	signe = 1;
	nbr = 0;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (ATOI_ERROR);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((nbr * 10) + (str[i] - '0') < nbr)
			return (ATOI_ERROR);
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (signe * nbr);
}

int	ft_normalise_str_array(char ***str, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (ft_normalise_str((*str) + 1) != 0)
			return (1);
	}
	return (1);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned long long	i;
	unsigned long long	y;

	i = 0;
	while (dest[i] != '\0')
		i++;
	y = 0;
	while (src[y] != '\0')
	{
		dest[i] = src[y];
		i++;
		y++;
	}
	dest[i] = '\0';
	return (dest);
}