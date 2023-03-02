/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_num2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:44:34 by pichen            #+#    #+#             */
/*   Updated: 2023/02/26 23:39:51 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_convert_num.h"
#include "ft_string.h"

char	*put_into_char(char **str, int len)
{
	int		i;
	int		k;
	char	*print_str;
	size_t	length;

	i = -1;
	length = 0;
	while (++i < len)
		length += ft_strlen(str[i]);
	print_str = malloc(sizeof(char) * (length + len));
	if (print_str == NULL)
		return (NULL);
	i = -1;
	k = 0;
	while (i < len)
	{
		ft_strcat(print_str, str[i]);
		i++;
	}
	print_str[k] = '\0';
	return (print_str);
}

char	*ft_convert_num(unsigned int num, char *dict_path)
{
	unsigned int	*a;
	int				i;
	int				len;
	char			**converted_a;

	len = count_len(num);
	a = (unsigned int *)malloc(sizeof(unsigned int) * len);
	i = 0;
	while (i < len)
	{
		a[i] = 21;
		i++;
	}
	ft_convert_num_int(a, num, 0, 0);
	converted_a = ft_get_entries_for(a, len, dict_path);
	if (converted_a == NULL)
		return (NULL);
	free(a);
	ft_free_str_arr(&converted_a, len);
	return (put_into_char(converted_a, len));
}
