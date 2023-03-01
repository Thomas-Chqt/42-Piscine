/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:05:28 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/01 18:46:29 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	**ft_free_str_array(char ***str_array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if ((*str_array)[i] != NULL)
			free((*str_array)[i]);
		i++;
	}
	free((*str_array));
	return (NULL);
}

void	ft_memcpy(void *src, size_t src_len, void *dest)
{
	size_t	i;

	i = 0;
	while (i < src_len)
	{
		((uint8_t *)dest)[i] = ((uint8_t *)src)[i];
		i++;
	}
}
