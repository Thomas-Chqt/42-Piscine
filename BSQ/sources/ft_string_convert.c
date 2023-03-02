/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:53:12 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/01 19:02:50 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

ssize_t	ft_atoi(const char *str)
{
	unsigned int	nbr;
	int				i;

	nbr = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((nbr * 10) + (str[i] - '0') < nbr)
			return (ATOI_ERROR);
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (ATOI_ERROR);
	return (nbr);
}
