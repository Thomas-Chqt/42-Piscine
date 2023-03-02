/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files_edit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:34:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/26 16:35:23 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_files.h"

int	ft_move_cursor(t_file *file, size_t new_pos)
{
	ssize_t	return_value;
	size_t	i;
	uint8_t	buffer;

	return_value = ft_reopen_file(file);
	if (return_value != 0)
		return (return_value);
	i = 0;
	while (i < new_pos)
	{
		return_value = read(file->file_descriptor, &buffer, 1);
		if (return_value <= 0)
		{
			if (return_value == 0)
				errno = END_OF_FILE;
			return ((int)READ_ERROR);
		}
		i++;
	}
	return (0);
}
