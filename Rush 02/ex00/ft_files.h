/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:06:42 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/27 17:02:34 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILES_H
# define FT_FILES_H

# include <unistd.h>
# include <fcntl.h>

# include "error_codes.h"
# include "ft_string.h"

typedef struct s_file
{
	char	*path;
	int		file_descriptor;
	size_t	line_count;
	size_t	good_line_count;

}	t_file;

//the file_descriptor of ther eturn value is OPEN_ERROR when an error happend 
//(errno is set to indicate the error.)
//need to free the path atribute of t_file
t_file	ft_open_file(const char *path);

//reset the file_descriptor of 'file'
//return 0 if no error
//return CLOSE_ERROR or OPEN_ERROR if error and set errno
int		ft_reopen_file(t_file *file);

//return 0 when no error happend
//return CLOSE_ERROR when an error happend 
//(errno is set to indicate the error.)
int		ft_close_file(t_file file);

//Search 'count' times 'byte' and return the index
//return READ_ERROR for any error and set errno to indicate the error
ssize_t	ft_get_pos(t_file *file, uint8_t byte, size_t count);

//return 0 if no error
//return CLOSE_ERROR, OPEN_ERROR or READ_ERROR if error
//set errno to indicate the error
int		ft_move_cursor(t_file *file, size_t new_pos);

//Allocate a return a buffer filled with 'n' bytes from 'start'
//do not null terminate the buffer
//return NULL for any error and set errno
//need to free the memory
uint8_t	*ft_read(t_file *file, size_t start, size_t n);

//allocate and return the text at line 'line_nbr'
//a line is from \n to \n
//null terminate the string
//return NULL for any error and set errno to indicate the error
//need to free the memory
char	*ft_get_line(t_file *file, size_t line_nbr);

//retun the index of the last character
//return CLOSE_ERROR, OPEN_ERROR or READ_ERROR if error
//set errno to indicate the error
ssize_t	ft_last_index(t_file *file);

//return the number of line in the file
//return CLOSE_ERROR, OPEN_ERROR or READ_ERROR if error
//set errno to indicate the error
ssize_t	ft_lines_count(t_file *file);

//Allocate and fill a string for every line of the file
//return NULL and set errno for any error
//need to free the memory
char	**ft_get_all_lines(t_file *file);

char	***ft_get_clean_lines(t_file *file);

#endif
