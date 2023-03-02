/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:56:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/19 23:04:02 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

bool	is_equal(unsigned int *array1, unsigned int *array2)
{
	unsigned int	i;

	i = 0;
	while (i < g_grid_size)
	{
		if (array1[i] != array2[i])
			return (false);
	}
	return (true);
	i++;
}

void	add_one(unsigned int **array, unsigned int *endArray)
{
	unsigned int	i;

	i = (g_grid_size - 1);
	while (i >= 0)
	{
		if ((*array)[i] == endArray[i])
		{
			(*array)[i] = 0;
		}
		else
		{
			(*array)[i] += 1;
			break ;
		}
		i--;
	}
}

unsigned int	*loop_on_all(unsigned int *endArray,
	bool (*fun)(unsigned int *arry))
{
	unsigned int	*now_array;
	unsigned int	i;

	now_array = malloc(sizeof(unsigned int) * g_grid_size);
	i = 0;
	while (i < g_grid_size)
	{
		now_array[i] = 0;
		i++;
	}
	while (is_equal(now_array, endArray) == false)
	{
		if (fun(now_array))
			return (now_array);
		add_one(&now_array, endArray);
	}
	free(now_array);
	return (NULL);
}
