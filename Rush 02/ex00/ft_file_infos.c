/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:25:11 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/26 19:21:05 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_files.h"

ssize_t	ft_last_index(t_file *file)
{
	ssize_t	return_value;
	ssize_t	i;
	uint8_t	buffer;

	return_value = (ssize_t)ft_reopen_file(file);
	if (return_value != 0)
		return (return_value);
	i = 0;
	errno = 0;
	while (errno != END_OF_FILE)
	{
		return_value = read(file->file_descriptor, &buffer, 1);
		if (return_value <= 0)
		{
			if (return_value == 0)
				errno = END_OF_FILE;
			else
				return ((ssize_t)READ_ERROR);
		}
		i++;
	}
	return (i - 1);
}

ssize_t	ft_lines_count(t_file *file)
{
	size_t	count;
	ssize_t	return_value;

	errno = 0;
	count = 0;
	while (errno != END_OF_FILE)
	{
		return_value = ft_get_pos(file, (uint8_t) '\n', count + 1);
		if (return_value == (ssize_t)READ_ERROR && errno != END_OF_FILE)
			return (return_value);
		count++;
	}
	return (count);
}
