/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constraint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:39:32 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/19 23:14:25 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constraint.h"

unsigned int	*ft_get_collum(unsigned int **boxes, unsigned int index);
unsigned int	*ft_reversed(unsigned int *boxes);
unsigned int	ft_get_visible(unsigned int *boxes);
bool			ft_is_same_nbr(unsigned int *boxes);

unsigned int	*ft_reversed(unsigned int *boxes)
{
	unsigned int	*reversed_boxes_ptr;
	unsigned int	i;

	reversed_boxes_ptr = malloc(sizeof(unsigned int) * g_grid_size);
	i = 0;
	while (i < g_grid_size)
	{
		reversed_boxes_ptr[i] = boxes[g_grid_size - 1 - i];
		i++;
	}
	return (reversed_boxes_ptr);
}

unsigned int	ft_get_visible(unsigned int *boxes)
{
	unsigned int	count;
	unsigned int	bigest;
	unsigned int	i;

	count = 1;
	bigest = boxes[0];
	i = 1;
	while (i < g_grid_size)
	{
		if (boxes[i] > bigest)
		{
			count++;
			bigest = boxes[i];
		}
		i++;
	}
	return (count);
}

bool	ft_is_same_nbr(unsigned int *boxes)
{
	unsigned int	expected_nbr;
	unsigned int	findede_nbr;
	unsigned int	i;

	expected_nbr = 0;
	i = 1;
	while (i < (g_grid_size + 1))
	{
		expected_nbr += i;
		i++;
	}
	findede_nbr = 0;
	i = 0;
	while (i < g_grid_size)
	{
		findede_nbr += boxes[i];
		i++;
	}
	return (expected_nbr != findede_nbr);
}

bool	ft_is_match(unsigned int *boxes, t_constraint constraint)
{
	unsigned int	*reversed_boxes;

	if (ft_is_same_nbr(boxes))
		return (false);
	if (ft_get_visible(boxes) != constraint.left_top)
		return (false);
	reversed_boxes = ft_reversed(boxes);
	if (ft_get_visible(reversed_boxes) != constraint.right_bottom)
	{
		free(reversed_boxes);
		return (false);
	}
	free(reversed_boxes);
	return (true);
}

bool	ft_is_resolv(void)
{
	unsigned int	*collum;
	unsigned int	i;

	i = 0;
	while (i < g_grid_size)
	{
		collum = ft_get_collum(g_grid.boxes, i);
		if (ft_is_match(collum, g_grid.v_constraint[i]) == false)
			return (false);
		free(collum);
		i++;
	}
	i = 0;
	while (i < g_grid_size)
	{
		if (ft_is_match(g_grid.boxes[i], g_grid.h_constraint[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
