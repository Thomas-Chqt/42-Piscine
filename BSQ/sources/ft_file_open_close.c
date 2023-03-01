/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_open_close.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:46:17 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/01 12:29:21 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file_back.h"

t_file	ft_open_file(const char *path)
{
	t_file	file;

	file.file_descriptor = open(path, O_RDONLY);
	if (file.file_descriptor < 0)
		file.file_descriptor = OPEN_ERROR;
	else
		file.path = ft_strdup(path);
	if (file.path == NULL)
		errno = ALLOCATION_ERROR;
	return (file);
}

int	ft_reopen_file(t_file *file)
{
	if (close(file->file_descriptor) < 0)
		return (CLOSE_ERROR);
	file->file_descriptor = open(file->path, O_RDONLY);
	if (file->file_descriptor < 0)
		return (OPEN_ERROR);
	return (0);
}

int	ft_close_file(t_file *file)
{
	free(file->path);
	file->path = NULL;
	if (close(file->file_descriptor) < 0)
		return (CLOSE_ERROR);
	file->file_descriptor = 0;
	return (0);
}
