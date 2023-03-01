/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:34:54 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/28 19:59:15 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_back.h"

t_box	ft_get_box_struc(t_point point, t_map *map)
{
	return (map->matrix[point.y][point.x]);
}

t_box	ft_get_box_point(size_t x, size_t y, t_map *map)
{
	return (map->matrix[y][x]);
}
