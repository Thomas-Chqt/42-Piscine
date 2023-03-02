/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:59:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/23 18:29:27 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned long	ft_get_split_count(char *str, char *charset);
int				ft_contain(char *array, char c);
void			ft_set_splited_array(char ***splited_array,
					char *str, char *charset);
char			*ft_c_s(char *src, unsigned long size);

char	**ft_split(char *str, char *charset)
{
	unsigned long	split_count;
	char			**splited_array;

	if (str == NULL || charset == NULL)
		return (NULL);
	split_count = ft_get_split_count(str, charset);
	if (split_count == 0)
	{
		splited_array = malloc(sizeof(char *));
		splited_array[0] = 0;
		return (splited_array);
	}
	splited_array = malloc(sizeof(char *) * (split_count + 1));
	ft_set_splited_array(&splited_array, str, charset);
	return (splited_array);
}

unsigned long	ft_get_split_count(char *str, char *charset)
{
	unsigned long	split_count;
	unsigned long	i;
	unsigned long	c_s_s;	

	split_count = 0;
	i = 0;
	c_s_s = 0;
	while (str[i])
	{
		if (ft_contain(charset, str[i]) && c_s_s > 0)
		{
			split_count++;
			c_s_s = 0;
			i++;
		}
		else
		{
			c_s_s++;
			i++;
		}
	}
	if (c_s_s > 0)
		split_count++;
	return (split_count);
}

int	ft_contain(char *array, char c)
{
	unsigned long	i;

	i = 0;
	while (array[i])
	{
		if (array[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_set_splited_array(char ***splited_array, char *str, char *charset)
{
	unsigned long	s_i;
	unsigned long	i;
	unsigned long	c_s_s;	

	s_i = 0;
	i = 0;
	c_s_s = 0;
	while (str[i])
	{
		if (ft_contain(charset, str[i]) && c_s_s > 0)
		{
			(*splited_array)[s_i] = ft_c_s(str + i - c_s_s, c_s_s);
			s_i++;
			c_s_s = 0;
		}
		if (ft_contain(charset, str[i]) == 0)
			c_s_s++;
		i++;
	}
	if (c_s_s > 0)
	{
		(*splited_array)[s_i] = ft_c_s(str + i - c_s_s, c_s_s);
		s_i++;
	}
	(*splited_array)[s_i] = 0;
}

char	*ft_c_s(char *src, unsigned long size)
{
	char			*new_split;
	unsigned long	i;

	new_split = malloc(sizeof(char) * (size + 1));
	if (new_split == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_split[i] = src[i];
		i++;
	}
	new_split[i] = '\0';
	return (new_split);
}
