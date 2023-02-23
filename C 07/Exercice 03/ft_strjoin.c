/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:32:21 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/23 13:51:43 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned long	ft_strlen(char *str);
char			*malloc_joined_str(int size, char **strs, char *sep);
void			ft_creat_joined_str(char **joined_str_ptr, int size,
					char **strs, char *sep);
void			ft_append(char **joined_str_ptr,
					unsigned long long *joined_str_c, char *str);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined_str;

	if (size <= 0)
	{
		joined_str = malloc(sizeof(char));
		if (joined_str != NULL)
			joined_str[0] = '\0';
		return (joined_str);
	}
	joined_str = malloc_joined_str(size, strs, sep);
	if (joined_str == NULL)
		return (NULL);
	ft_creat_joined_str(&joined_str, size, strs, sep);
	return (joined_str);
}

unsigned long	ft_strlen(char *str)
{
	unsigned long	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*malloc_joined_str(int size, char **strs, char *sep)
{
	char				*joined_str;
	unsigned long long	joined_str_len;
	int					i;

	joined_str_len = 0;
	i = 0;
	while (i < size)
	{
		joined_str_len += ft_strlen(strs[i]);
		i++;
	}
	joined_str_len += ft_strlen(sep) * (size - 1);
	joined_str_len++;
	joined_str = malloc(sizeof(char) * joined_str_len);
	return (joined_str);
}

void	ft_creat_joined_str(char **joined_str_ptr, int size,
					char **strs, char *sep)
{
	unsigned long long	joined_str_c;
	int					str_index;

	joined_str_c = 0;
	str_index = 0;
	if (strs[str_index] != NULL)
		ft_append(joined_str_ptr, &joined_str_c, strs[str_index]);
	str_index++;
	while (str_index < size)
	{
		if (sep != NULL)
			ft_append(joined_str_ptr, &joined_str_c, sep);
		if (strs[str_index] != NULL)
			ft_append(joined_str_ptr, &joined_str_c, strs[str_index]);
		str_index++;
	}
	(*joined_str_ptr)[joined_str_c] = '\0';
}

void	ft_append(char **joined_str_ptr,
			unsigned long long *joined_str_c, char *str)
{
	unsigned long long	str_c;

	str_c = 0;
	while (str[str_c])
	{
		(*joined_str_ptr)[*joined_str_c] = str[str_c];
		str_c++;
		(*joined_str_c)++;
	}
}
