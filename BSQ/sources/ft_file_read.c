/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:15:09 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/01 13:02:39 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file_back.h"

char	*ft_read_file(t_file *file)
{
	char	*file_str;
	ssize_t	return_value;
	size_t	file_len;

	return_value = ft_file_len(file);
	if (return_value < 0)
		return (NULL);
	file_len = (size_t)return_value;
	if (ft_reopen_file(file) < 0)
		return (NULL);
	file_str = malloc(sizeof(char) * (file_len + 1));
	if (file_str == NULL)
		return (NULL);
	return_value = read(file->file_descriptor, file_str, file_len);
	if (return_value <= 0)
	{
		if (return_value == 0)
			errno = END_OF_FILE;
		else
			errno = READ_ERROR;
		free(file_str);
		return (NULL);
	}
	file_str[file_len] = '\0';
	return (file_str);
}

ssize_t	ft_get_lines(t_file *file, char ***lines)
{
	char	*file_str;
	size_t	lines_count;

	file_str = ft_read_file(file);
	if (file_str == NULL)
		return (READ_ERROR);
	*lines = ft_split(&file_str, '\n', &lines_count);
	if (lines == NULL)
		return (-1);
	return (lines_count);
}

char	*ft_get_first_line(t_file *file)
{
	char	*line;
	uint8_t	buffer;
	size_t	line_len;

	if (ft_reopen_file(file) != 0)
		return (NULL);
	errno = 0;
	line_len = 0;
	while (errno != END_OF_FILE && buffer != '\n')
	{
		if (ft_read(file->file_descriptor, &buffer, 1) < 0)
			return (NULL);
		if (errno != END_OF_FILE && buffer != '\n')
			line_len++;
	}
	line = malloc(sizeof(char) * (line_len + 1));
	if (line == NULL || ft_reopen_file(file) != 0
		|| read(file->file_descriptor, line, line_len) <= 0)
	{
		if (line != NULL)
			free(line);
		return (NULL);
	}
	line[line_len] = '\0';
	return (line);
}

int	ft_read(int file_des, void *buffer, size_t len)
{
	ssize_t	return_value;

	return_value = read(file_des, buffer, len);
	if (return_value < 0)
		return (READ_ERROR);
	if (return_value == 0)
		errno = END_OF_FILE;
	return (0);
}
