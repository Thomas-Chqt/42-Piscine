/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_stdin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:23:42 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/01 20:18:28 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file_back.h"

char	*ft_read_stdin(void)
{
	char	*str;
	size_t	str_len;
	char	buffer[1024];
	size_t	read_len;

	str_len = 1;
	str = malloc(sizeof(char) * str_len);
	if (str == NULL)
		return (NULL);
	read_len = 1;
	while (read_len > 0)
	{
		read_len = read(STDIN_FILENO, buffer, 1024);
		if (read_len < 0)
		{
			free(str);
			return (NULL);
		}
		if (ft_realloc(&str, str_len, str_len + read_len) == NULL)
			return (NULL);
		ft_memcpy(buffer, read_len, str + (str_len - 1));
		str_len += read_len;
	}
	str[str_len - 1] = '\0';
	return (str);
}

char	*ft_realloc(char **buffer_ptr, size_t previous_size, size_t new_size)
{
	char	*new_buffer;

	if (previous_size == new_size)
		return (*buffer_ptr);
	new_buffer = malloc(sizeof(char) * new_size);
	if (new_buffer == NULL)
		return (NULL);
	if ((*buffer_ptr) != NULL)
	{
		ft_memcpy((*buffer_ptr), previous_size, new_buffer);
		free(*buffer_ptr);
	}
	(*buffer_ptr) = new_buffer;
	return (new_buffer);
}
