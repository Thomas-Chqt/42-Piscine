/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:25:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/01 21:42:58 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_back.h"

int	ft_parse_header(char *first_line, t_map *map)
{
	size_t	i;
	char	*line_count_str;
	ssize_t	return_value;

	i = ft_strlen(first_line) - 1;
	if ((i < 3) || (is_printable(first_line[i]) == false))
		return (HEADER_ERROR);
	map->full_c = first_line[i];
	if (is_printable(first_line[--i]) == false)
		return (HEADER_ERROR);
	map->obstacle_c = first_line[i];
	if (is_printable(first_line[--i]) == false)
		return (HEADER_ERROR);
	map->empty_c = first_line[i];
	line_count_str = ft_strldup(first_line, i);
	if (line_count_str == NULL)
		return (HEADER_ERROR);
	return_value = ft_atoi(line_count_str);
	free(line_count_str);
	if (return_value < 0)
		return (HEADER_ERROR);
	map->height = (size_t)return_value;
	return (0);
}

int	ft_read_header(t_map *map)
{
	char	*first_line;

	first_line = ft_get_first_line(&(map->file));
	if (first_line == NULL)
		return (HEADER_ERROR);
	if (ft_parse_header(first_line, map) != 0)
	{
		free(first_line);
		return (HEADER_ERROR);
	}
	free(first_line);
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

int	ft_parse_body(char **lines, size_t lines_count, t_map *map)
{
	size_t	lines_len;
	size_t	i;

	if (lines_count != (map->height + 1))
		return (BODY_ERROR);
	lines_len = ft_strlen(lines[1]);
	i = 1;
	while (i < lines_count)
	{
		if (ft_strlen(lines[i]) != lines_len)
			return (BODY_ERROR);
		if (ft_is_valid_line(lines[i], map) == false)
			return (BODY_ERROR);
		i++;
	}
	map->width = lines_len;
	return (0);
}

int	ft_read_body(t_map *map)
{
	char	**lines;
	ssize_t	return_value;
	size_t	lines_count;

	return_value = ft_get_lines(&(map->file), &lines);
	if (lines == NULL)
		return (BODY_ERROR);
	if (return_value < 0)
		return (BODY_ERROR);
	lines_count = (size_t)return_value;
	if (ft_parse_body(lines, lines_count, map) != 0)
	{
		ft_free_str_array(&lines, lines_count);
		return (BODY_ERROR);
	}
	if (ft_setup_matrix(lines, map) != 0)
	{
		ft_free_str_array(&lines, lines_count);
		return (BODY_ERROR);
	}
	ft_free_str_array(&lines, lines_count);
	return (0);
}
