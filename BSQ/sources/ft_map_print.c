/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:38:29 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/28 20:01:23 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_back.h"

void	ft_print_map(t_map *map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_put_box(map->matrix[y][x], map);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void	ft_put_box(t_box box, t_map *map)
{
	if (box == empty)
		write(1, &(map->empty_c), 1);
	else if (box == obstacle)
		write(1, &(map->obstacle_c), 1);
	else if (box == full)
		write(1, &(map->full_c), 1);
	else
		write(1, "e", 1);
}
