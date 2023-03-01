/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:24:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/28 18:53:34 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_back.h"

bool	ft_is_valid_line(char *line, t_map *map)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (ft_char_to_box(line[i], map) == undefined)
			return (false);
		if (ft_char_to_box(line[i], map) == full)
			return (false);
		i++;
	}
	return (true);
}

t_box	ft_char_to_box(char c, t_map *map)
{
	if (c == map->empty_c)
		return (empty);
	if (c == map->obstacle_c)
		return (obstacle);
	if (c == map->full_c)
		return (full);
	return (undefined);
}
