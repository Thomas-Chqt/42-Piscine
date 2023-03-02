/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:19:56 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/26 19:27:32 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_files.h"
#include "ft_dict_file.h"

ssize_t	ft_get_pos(t_file *file, uint8_t byte, size_t count)
{
	ssize_t	return_value;
	uint8_t	buffer;
	ssize_t	i;
	size_t	hit_count;

	return_value = (ssize_t)ft_reopen_file(file);
	if (return_value != 0)
		return (return_value);
	buffer = 0xFF;
	i = 0;
	hit_count = 0;
	while (hit_count < count || buffer != byte)
	{
		return_value = read(file->file_descriptor, &buffer, 1);
		if (return_value <= 0)
		{
			if (return_value == 0)
				errno = END_OF_FILE;
			return ((ssize_t)READ_ERROR);
		}
		if (buffer == byte)
			hit_count++;
		i++;
	}
	return (i - 1);
}

uint8_t	*ft_read(t_file *file, size_t start, size_t n)
{
	uint8_t	*buffer;
	ssize_t	return_value;

	buffer = malloc(sizeof(uint8_t) * n);
	if (buffer == NULL)
		errno = ALLOCATION_ERROR;
	else
	{
		if (ft_move_cursor(file, start) != 0)
			return (NULL);
		else
		{
			return_value = read(file->file_descriptor, buffer, n);
			if (return_value < 0)
			{
				errno = READ_ERROR;
				if (return_value < (ssize_t)n)
					errno = END_OF_FILE;
				return (NULL);
			}
		}
	}
	return (buffer);
}

char	*ft_get_line(t_file *file, size_t line_nbr)
{
	char	*line;
	uint8_t	*buffer;
	ssize_t	start_index;
	ssize_t	end_index;

	start_index = ft_get_pos(file, (uint8_t) '\n', line_nbr);
	if (start_index == (ssize_t)READ_ERROR && line_nbr != 0)
		return (NULL);
	start_index++;
	if (line_nbr == 0)
		start_index = 0;
	end_index = ft_get_pos(file, (uint8_t) '\n', line_nbr + 1);
	if (end_index == (ssize_t)READ_ERROR)
	{
		if (errno == END_OF_FILE)
			end_index = ft_last_index(file);
		else
			return (NULL);
	}
	buffer = ft_read(file, (size_t)start_index,
			(size_t)end_index - (size_t)start_index);
	if (buffer == NULL)
		return (NULL);
	line = ft_creat_str(&buffer, (size_t)end_index - (size_t)start_index);
	return (line);
}

char	**ft_get_all_lines(t_file *file)
{
	char	**str_array;
	ssize_t	file_line_count;
	ssize_t	i;

	file_line_count = ft_lines_count(file);
	if (file_line_count < 0)
		return (NULL);
	str_array = malloc(sizeof(char *) * file_line_count);
	if (str_array == NULL)
	{
		errno = ALLOCATION_ERROR;
		return (NULL);
	}
	i = 0;
	while (i < file_line_count)
	{
		str_array[i] = ft_get_line(file, i);
		if (str_array[i] == NULL)
			return (NULL);
		i++;
	}
	return (str_array);
}

char	***ft_get_clean_lines(t_file *file)
{
	ssize_t	return_value;
	char	**lines;
	char	***splited_lines;
	size_t	lines_count;
	size_t	i;

	lines = ft_get_all_lines(file);
	if (lines == NULL)
		return (NULL);
	return_value = ft_lines_count(file);
	if (return_value < 0)
		return (NULL);
	lines_count = (size_t)return_value;
	splited_lines = ft_split_all_lines(&lines, lines_count);
	if (splited_lines == NULL)
		return (NULL);
	i = 0;
	while (i < lines_count)
	{
		if (ft_normalise_str(splited_lines[i]) == ALLOCATION_ERROR
			|| ft_normalise_str(splited_lines[i] + 1) == ALLOCATION_ERROR)
			return (NULL);
		i++;
	}
	return (splited_lines);
}
