/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:08:19 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/26 23:25:42 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	ft_free_splided_line_array(char ****splited_lines, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if ((*splited_lines)[i] != NULL)
		{
			free((*splited_lines)[i][0]);
			free((*splited_lines)[i][1]);
			free((*splited_lines)[i]);
		}
		i++;
	}
	free((*splited_lines));
}

void	ft_free_entry_array(t_entry **array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if ((*array)[i].str != NULL)
		{
			free((*array)[i].str);
		}
		i++;
	}
	free(*array);
}

void	ft_free_str_arr(char ***str_array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if ((*str_array)[i] != NULL)
		{
			free((*str_array)[i]);
		}
		i++;
	}
	free(*str_array);
}
