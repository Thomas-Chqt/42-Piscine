/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:35:36 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/16 22:40:49 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	ret;
	unsigned int	k;

	i = 0;
	ret = 0;
	k = 0;
	while (dest[i] != '\0')
		i++;
	while (src[ret] != '\0')
		ret++;
	if (size <= i)
		ret += size;
	else
		ret += i;
	while (src[k] != '\0' && i + 1 < size)
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (ret);
}
