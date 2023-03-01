/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_api.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:35:05 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/01 18:45:58 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_API_H
# define FT_FILE_API_H

# include "error_codes.h"
# include "ft_string.h"

typedef struct s_file
{
	char	*path;
	int		file_descriptor;

}	t_file;

//the file_descriptor of the return value is 
//OPEN_ERROR or the file path is NULL when an error happend 
//(errno is set to indicate the error.)
//need to free the path atribute
t_file	ft_open_file(const char *path);

//return 0 when no error happend
//return CLOSE_ERROR when an error happend 
//(errno is set to indicate the error.)
//automaticaly free the path atribute
int		ft_close_file(t_file *file);

//return the size (in character) of the file
//return CLOSE_ERROR, OPEN_ERROR or READ_ERROR if error
//set errno to indicate the error
ssize_t	ft_file_len(t_file *file);

//Allocate and fill the array of lines
//return the number of lines
//return < 0 if error
//lines is NULL if allocation error
//need to free the memory
ssize_t	ft_get_lines(t_file *file, char ***lines);

//allocate and retun the first line
//str is null terminated
//return NULL if error
//set errno to indicate the error
//need to free the return value
char	*ft_get_first_line(t_file *file);

//need to free th buffer
//return NULL for error
char	*ft_read_stdin(void);

#endif