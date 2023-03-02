/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:12:20 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/26 19:27:20 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_dict_file.h"

char	***ft_split_all_lines(char ***lines, size_t count)
{
	char	***splided_lines;
	size_t	i;

	splided_lines = malloc(sizeof(char **) * count);
	if (splided_lines == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		splided_lines[i] = ft_split_str((*lines) + i);
		i++;
	}
	free(*lines);
	return (splided_lines);
}

size_t	ft_remove_bad_line(char ****splited_lines, size_t count)
{
	size_t	i;
	size_t	good_line_count;

	good_line_count = 0;
	i = 0;
	while (i < count)
	{
		if (ft_is_bad_line(*splited_lines, i, (*splited_lines)[i]))
		{
			free((*splited_lines)[i][0]);
			free((*splited_lines)[i][1]);
			free((*splited_lines)[i]);
			(*splited_lines)[i] = NULL;
		}
		if ((*splited_lines)[i] != NULL)
			good_line_count++;
		i++;
	}
	return (good_line_count);
}

int	ft_fill_struct_array(t_entry **array, char ***splited_lines, size_t count)
{
	size_t	i;
	size_t	y;
	t_entry	new_struct;

	i = 0;
	y = 0;
	while (i < count)
	{
		if (splited_lines[i] != NULL)
		{
			new_struct.nbr = (unsigned int)ft_atoi(splited_lines[i][0]);
			new_struct.str = ft_strdup(splited_lines[i][1]);
			(*array)[y] = new_struct;
			y++;
		}
		i++;
	}
	return (0);
}

bool	ft_is_bad_line(char ***array, size_t len, char **line)
{
	if (ft_atoi(line[0]) < 0 || ft_atoi(line[0]) > UINT_MAX)
		return (true);
	if (ft_is_bad_str(line[1]))
		return (true);
	if (ft_contain(array, len, line))
		return (true);
	return (false);
}

bool	ft_contain(char ***array, size_t len, char **value)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if ((array[i] != NULL) && ((ft_atoi(array[i][0]) == ft_atoi(value[0]))))
			return (true);
		i++;
	}
	return (false);
}
