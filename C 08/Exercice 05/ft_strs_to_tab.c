/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 23:01:24 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/23 23:19:31 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

long long	ft_strlen(char *str);
char		*ft_strdup(char *src);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*array;
	int			i;

	array = malloc(sizeof(t_stock_str) * (ac + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		array[i].size = ft_strlen(av[i]);
		array[i].str = av[i];
		array[i].copy = ft_strdup(av[i]);
		i++;
	}
	array[i].size = 0;
	array[i].str = 0;
	array[i].copy = 0;
	return (array);
}

char	*ft_strdup(char *src)
{
	long long	len;
	char		*cp;

	len = ft_strlen(src);
	cp = malloc(sizeof(char) * (len + 1));
	if (cp == NULL)
	{
		return (NULL);
	}
	while (len >= 0)
	{
		cp[len] = src[len];
		len--;
	}
	return (cp);
}

long long	ft_strlen(char *str)
{
	long long	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
