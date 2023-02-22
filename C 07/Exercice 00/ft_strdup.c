/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:30:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/22 22:09:28 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>

long long	ft_strlen(char *str);

char	*ft_strdup(char *src)
{
	long long	len;
	char		*cp;

	len = ft_strlen(src);
	cp = malloc(sizeof(char) * (len + 1));
	if (cp == NULL)
	{
		errno = ENOMEM;
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
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
