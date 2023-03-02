/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:42:18 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/28 20:01:41 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_api.h"

int	ft_set_box_struc(t_point point, t_map *map, t_box box)
{
	map->matrix[point.y][point.x] = box;
	return (0);
}

int	ft_set_box_point(size_t x, size_t y, t_map *map, t_box box)
{
	map->matrix[y][x] = box;
	return (0);
}

int	ft_insert(t_solution solution, t_map *map)
{
	size_t	x;
	size_t	y;

	y = solution.point.y;
	while (y < solution.point.y + solution.size)
	{
		x = solution.point.x;
		while (x < solution.point.x + solution.size)
		{
			ft_set_box_point(x, y, map, full);
			x++;
		}
		y++;
	}
	return (0);
}
