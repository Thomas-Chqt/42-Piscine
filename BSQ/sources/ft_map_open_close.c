/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_open_close.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:59:25 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/01 21:44:34 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_back.h"

int	ft_init_map(t_map *map, const char *file_path)
{
	map->file = ft_open_file(file_path);
	map->matrix = NULL;
	if (map->file.file_descriptor == OPEN_ERROR)
		return (OPEN_ERROR);
	if (ft_read_header(map) != 0)
		return (HEADER_ERROR);
	if (ft_read_body(map) != 0)
		return (BODY_ERROR);
	return (0);
}

int	ft_init_map_stdin(t_map *map, char **data)
{
	char	**lines;
	size_t	line_count;

	map->matrix = NULL;
	map->file.path = NULL;
	if ((*data)[0] == '\0')
	{
		free(*data);
		return (OPEN_ERROR);
	}
	lines = ft_split(data, '\n', &line_count);
	if (lines == NULL)
	{
		free(*data);
		return (OPEN_ERROR);
	}
	if ((ft_read_header_stdin(map, lines) != 0)
		|| (ft_read_body_stdin(map, lines, line_count) != 0))
	{
		ft_free_str_array(&lines, line_count);
		return (BODY_ERROR);
	}
	ft_free_str_array(&lines, line_count);
	return (0);
}

int	ft_deinit_map(t_map *map)
{
	if (map->matrix != NULL)
		ft_free_matrix(&(map->matrix), map->height);
	if (map->file.path == NULL)
		return (0);
	return (ft_close_file(&(map->file)));
}

int	ft_read_body_stdin(t_map *map, char **lines, size_t	lines_count)
{
	if (ft_parse_body(lines, lines_count, map) != 0)
		return (BODY_ERROR);
	if (ft_setup_matrix(lines, map) != 0)
		return (BODY_ERROR);
	return (0);
}

int	ft_read_header_stdin(t_map *map, char **lines)
{
	char	*first_line;

	first_line = lines[0];
	if (first_line == NULL)
		return (HEADER_ERROR);
	if (ft_parse_header(first_line, map) != 0)
	{
		return (HEADER_ERROR);
	}
	if (map->empty_c == map->full_c)
		return (HEADER_ERROR);
	if (map->full_c == map->obstacle_c)
		return (HEADER_ERROR);
	if (map->obstacle_c == map->empty_c)
		return (HEADER_ERROR);
	if (map->height < 1)
		return (HEADER_ERROR);
	return (0);
}
