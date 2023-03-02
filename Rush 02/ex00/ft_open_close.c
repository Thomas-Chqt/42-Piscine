/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:30:32 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/26 19:27:15 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_files.h"

t_file	ft_open_file(const char *path)
{
	t_file	file;

	file.file_descriptor = open(path, O_RDONLY);
	if (file.file_descriptor < 0)
		file.file_descriptor = OPEN_ERROR;
	file.path = ft_strdup(path);
	return (file);
}

int	ft_reopen_file(t_file *file)
{
	int	return_value;

	return_value = close((*file).file_descriptor);
	if (return_value < 0)
		return (CLOSE_ERROR);
	return_value = open((*file).path, O_RDONLY);
	if (return_value < 0)
		return (OPEN_ERROR);
	(*file).file_descriptor = return_value;
	return (0);
}

int	ft_close_file(t_file file)
{
	int	return_value;

	return_value = close(file.file_descriptor);
	if (return_value < 0)
		return (CLOSE_ERROR);
	return (0);
}
