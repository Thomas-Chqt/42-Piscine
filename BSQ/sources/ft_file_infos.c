/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:20:58 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/01 18:46:23 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file_back.h"

ssize_t	ft_file_len(t_file *file)
{
	ssize_t	return_value;
	size_t	file_len;
	uint8_t	buffer;

	return_value = ft_reopen_file(file);
	if (return_value != 0)
		return (return_value);
	file_len = 0;
	errno = 0;
	while (errno != END_OF_FILE)
	{
		return_value = read(file->file_descriptor, &buffer, 1);
		if (return_value <= 0)
		{
			if (return_value < 0)
				return (READ_ERROR);
			errno = END_OF_FILE;
		}
		else
			file_len++;
	}
	return (file_len);
}
