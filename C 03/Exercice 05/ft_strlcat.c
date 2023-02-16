/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:35:36 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/16 13:06:33 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlen(char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	y;
	unsigned int	ret;

	ret = ft_strlen(src) + ft_strlen(dest);
	i = ft_strlen(dest);
	y = 0;
	while (i < size - 1 && src[y] != '\0')
	{
		dest[i] = src[y];
		i++;
		y++;
	}
	dest[i] = '\0';
	return (ret);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}
