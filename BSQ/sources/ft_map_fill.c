/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:47:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/28 18:53:34 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_back.h"

int	ft_setup_matrix(char **lines, t_map *map)
{
	size_t	y;
	size_t	x;

	map->matrix = malloc(sizeof(t_box *) * map->height);
	if (map->matrix == NULL)
		return (-1);
	y = 0;
	while (y < map->height)
	{	
		map->matrix[y] = malloc(sizeof(t_box) * map->width);
		if (map->matrix[y] == NULL)
		{
			ft_free_matrix(&(map->matrix), y + 1);
			return (-1);
		}
		x = 0;
		while (x < map->width)
		{
			map->matrix[y][x] = ft_char_to_box(lines[y + 1][x], map);
			x++;
		}
		y++;
	}
	return (0);
}
