/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_entry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:56:44 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/26 19:26:42 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict_file.h"

char	*find_in_entry_array(t_entry *entries, size_t size, unsigned int nbr)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (entries[i].nbr == nbr)
			return (ft_strdup(entries[i].str));
		i++;
	}
	return (NULL);
}

char	**find_n_in_entry_array(t_entry *entries, size_t size,
			unsigned int *nbrs, size_t n)
{
	size_t	i;
	size_t	y;
	char	**finded_strs;

	finded_strs = malloc(sizeof(char *) * n);
	if (finded_strs == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		y = 0;
		while (y < size)
		{
			if (entries[y].nbr == nbrs[i])
			{
				finded_strs[i] = ft_strdup(entries[y].str);
				break ;
			}
			y++;
		}
		if (y >= size)
			return (NULL);
		i++;
	}
	return (finded_strs);
}

char	*ft_get_entry_for(unsigned int nbr, char *dict_path)
{
	t_file	file;
	t_entry	*entries;
	ssize_t	return_value;
	char	***splited_lines;
	char	*finded_str;

	file = ft_open_file(dict_path);
	if (file.file_descriptor == OPEN_ERROR)
		return (NULL);
	return_value = ft_lines_count(&file);
	if (return_value < 0)
		return (NULL);
	file.line_count = (size_t)return_value;
	splited_lines = ft_get_clean_lines(&file);
	if (splited_lines == NULL)
		return (NULL);
	free(file.path);
	file.good_line_count = ft_remove_bad_line(&splited_lines, file.line_count);
	entries = malloc(sizeof(t_entry) * file.good_line_count);
	if (ft_fill_struct_array(&entries, splited_lines, file.line_count) != 0)
		return (NULL);
	ft_free_splided_line_array(&splited_lines, file.line_count);
	finded_str = find_in_entry_array(entries, file.good_line_count, nbr);
	ft_free_entry_array(&entries, file.good_line_count);
	return (finded_str);
}

char	**ft_get_entries_for(unsigned int *nbrs, size_t n, char *dict_path)
{
	t_file	file;
	t_entry	*entries;
	ssize_t	return_value;
	char	***splited_lines;
	char	**finded_strs;

	file = ft_open_file(dict_path);
	if (file.file_descriptor == OPEN_ERROR)
		return (NULL);
	return_value = ft_lines_count(&file);
	if (return_value < 0)
		return (NULL);
	file.line_count = (size_t)return_value;
	splited_lines = ft_get_clean_lines(&file);
	if (splited_lines == NULL)
		return (NULL);
	free(file.path);
	file.good_line_count = ft_remove_bad_line(&splited_lines, file.line_count);
	entries = malloc(sizeof(t_entry) * file.good_line_count);
	if (ft_fill_struct_array(&entries, splited_lines, file.line_count) != 0)
		return (NULL);
	ft_free_splided_line_array(&splited_lines, file.line_count);
	finded_strs = find_n_in_entry_array(entries, file.good_line_count, nbrs, n);
	ft_free_entry_array(&entries, file.good_line_count);
	return (finded_strs);
}
