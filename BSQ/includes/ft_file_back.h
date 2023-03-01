/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_back.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:57:44 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/01 14:52:26 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_BACK_H
# define FT_FILE_BACK_H

# include <fcntl.h>
# include <unistd.h>
# include "ft_file_api.h"

//reset the file_descriptor of 'file'
//return 0 if no error
//return CLOSE_ERROR or OPEN_ERROR if error and set errno
int		ft_reopen_file(t_file *file);

//read the data like read
//return READ_ERROR for error
//set errno to END_OF_FILE when at the end
int		ft_read(int file_des, void *buffer, size_t len);

//return all file in a sigle string
//str is null terminated
//return NULL for any error and set errno
//need to free the string
char	*ft_read_file(t_file *file);

//alloc a new buffer, copy the memory and free the previous buffer
//return q pointer to the nez buffer
//need to free
char	*ft_realloc(char **buffer_ptr, size_t previous_size, size_t new_size);

#endif