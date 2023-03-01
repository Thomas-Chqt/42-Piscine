/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:16:46 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/01 19:48:45 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strdup(const char *src)
{
	char	*cp;
	size_t	i;

	cp = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (cp == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		cp[i] = src[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}

char	*ft_strldup(const char *src, size_t len)
{
	char	*cp;
	size_t	i;

	cp = malloc(sizeof(char) * (len + 1));
	if (cp == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cp[i] = src[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}

size_t	ft_get_split_count(char *str, char split_c,
			size_t *start_index, size_t *end_index)
{
	size_t	i;
	size_t	split_count;

	i = 0;
	while (str[i] && (str[i] == split_c))
		i++;
	*start_index = i;
	while (str[i])
		i++;
	i--;
	while (i >= 0 && (str[i] == split_c))
		i--;
	*end_index = i;
	split_count = 0;
	while (i > *start_index)
	{
		if (str[i] == split_c)
			split_count++;
		i--;
	}
	split_count++;
	return (split_count);
}

char	**ft_split(char **str, char split_c, size_t *split_count)
{
	char	**splited_array;
	size_t	indexs[2];
	ssize_t	char_i;
	size_t	split_i;
	size_t	split_len;

	(*split_count)
		= ft_get_split_count(*str, split_c, &(indexs[0]), &(indexs[1]));
	splited_array = malloc(sizeof(char *) * ((*split_count)));
	if (splited_array == NULL)
		return (NULL);
	split_i = 0;
	char_i = indexs[0] - 1;
	while (split_i < *split_count)
	{
		split_len = 0;
		while (((*str)[++char_i] && (*str)[char_i] != split_c))
			split_len++;
		splited_array[split_i]
			= ft_strldup((*str) + (char_i - split_len), split_len);
		if (splited_array[split_i++] == NULL)
			return (ft_free_str_array(&splited_array, split_i));
	}
	free(*str);
	return (splited_array);
}
