/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:10:00 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/12 16:27:05 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_INT 2147483647

typedef unsigned char	t_uint8;

int	ft_strlen(char *str);

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
			return (-1);
		if (len == (MAX_INT - 1))
			return (-2);
		len++;
	}
	return (len);
}
