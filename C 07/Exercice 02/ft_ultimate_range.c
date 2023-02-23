/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:40:28 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/23 11:57:07 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned long	size;
	unsigned long	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = (long)max - (long)min;
	*range = malloc(sizeof(int) * size);
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	if (size > INT_MAX)
		return (-1);
	return (size);
}
