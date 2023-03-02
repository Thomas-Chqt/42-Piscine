/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_infos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:27:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/26 19:27:55 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	ft_is_removeable(char c)
{
	if (c <= ' ' || c > '~')
		return (true);
	return (false);
}

bool	ft_is_bad_str(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_removeable(str[i]))
			return (true);
		i++;
	}
	return (false);
}
