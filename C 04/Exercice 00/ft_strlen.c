/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:09:29 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/20 20:52:08 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

typedef unsigned char	t_uint8;

int	ft_strlen(char *str)
{
	int		len;
	t_uint8	*offset;

	len = 0;
	offset = (t_uint8 *)str;
	while (*offset != '\0')
	{
		if ((*offset & 0x80) == 0x00)
			offset += 1;
		else if ((*offset & 0xe0) == 0xc0)
			offset += 2;
		else if ((*offset & 0xf0) == 0xe0)
			offset += 3;
		else if ((*offset & 0xf8) == 0xf0)
			offset += 4;
		else
			offset += 1;
		if (len == (INT_MAX - 1))
			return (-2);
		len++;
	}
	return (len);
}
