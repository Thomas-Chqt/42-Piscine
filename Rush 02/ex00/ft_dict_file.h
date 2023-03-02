/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_file.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:57:43 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/26 19:20:50 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICT_FILE_H
# define FT_DICT_FILE_H

# include "ft_files.h"
# include "ft_mem.h"

//Allocate and return the word for the number 'nbr' in the dict 'dict_path'
//return value is null terminated
//return NULL for any error and errno is set
//need to free the memory
char	*ft_get_entry_for(unsigned int nbr, char *dict_path);

//Allocate and return the words for the numbers 'nbrs' in the dict 'dict_path'
//return values are null terminated
//return values are in the same order than the nbrs
//return NULL for any error and errno is set
//need to free the memory
char	**ft_get_entries_for(unsigned int *nbrs, size_t n, char *dict_path);

//split every line by ':' and return an array for each lines
//every string is null terminated
//return NULL for allocation error
//allocate every strings, free the lines and the array of lines
//need to free the memory
char	***ft_split_all_lines(char ***lines, size_t count);

//free and nullify all the lines that contain bad string or that is in double
//return the number of non nul strings
size_t	ft_remove_bad_line(char ****splited_lines, size_t count);

//Fill a previouly allocated array of t_entry
//return 0 if no error
int		ft_fill_struct_array(t_entry **array,
			char ***splited_lines, size_t count);

bool	ft_contain(char ***array, size_t len, char **value);

bool	ft_is_bad_line(char ***array, size_t len, char **line);

char	*find_in_entry_array(t_entry *entries, size_t size, unsigned int nbr);

char	**find_n_in_entry_array(t_entry *entries, size_t size,
			unsigned int *nbrs, size_t n);

#endif