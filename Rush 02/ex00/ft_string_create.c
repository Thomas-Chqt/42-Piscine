/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:24:14 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/26 19:27:46 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strdup(const char *src)
{
	ssize_t	len;
	char	*cp;

	len = ft_strlen(src);
	cp = malloc(sizeof(char) * (len + 1));
	if (cp == NULL)
		return (NULL);
	while (len >= 0)
	{
		cp[len] = src[len];
		len--;
	}
	return (cp);
}

char	*ft_strdupl(const char *src, size_t len)
{
	char	*cp;
	ssize_t	slen;

	slen = (ssize_t)len;
	cp = malloc(sizeof(char) * (slen + 1));
	if (cp == NULL)
		return (NULL);
	cp[slen] = '\0';
	while (--slen >= 0)
		cp[slen] = src[slen];
	return (cp);
}

char	*ft_creat_str(uint8_t **buffer, size_t len)
{
	char	*str;
	size_t	i;

	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		errno = ALLOCATION_ERROR;
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		str[i] = (char)((*buffer)[i]);
		i++;
	}
	str[i] = '\0';
	free(*buffer);
	return (str);
}

char	**ft_split_str(char **str)
{
	char	**str_array;
	size_t	len;

	str_array = malloc(sizeof(char *) * 2);
	if (str_array == NULL)
		return (NULL);
	len = 0;
	while ((*str)[len] != ':' && (*str)[len] != '\0')
		len++;
	str_array[0] = ft_strdupl(*str, len);
	if (str_array[0] == NULL)
		return (NULL);
	str_array[1] = ft_strdup((*str) + (len + 1));
	if (str_array[1] == NULL)
		return (NULL);
	free(*str);
	return (str_array);
}
