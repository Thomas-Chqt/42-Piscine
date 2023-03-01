/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:15:36 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/01 14:52:27 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>

# include "error_codes.h"

size_t	ft_strlen(const char *str);

//allocate memory for a copy of 'str' and do the copy
//return NULL for allocation error
//null teminate the string
//need to free the memory
char	*ft_strdup(const char *src);

//allocate memory for a copy of 'str' and do the copy
//return NULL for allocation error
//null teminate the string
//need to free the memory
char	*ft_strldup(const char *src, size_t len);

//split str by split_c
//allocate new string and free str
//return NULL for any erro and set errno
//need to free the memory
char	**ft_split(char **str, char split_c, size_t *split_count);

size_t	ft_get_split_count(char *str, char split_c,
			size_t *start_index, size_t *end_index);

bool	is_printable(char c);

//return ATOI_ERROR for error
ssize_t	ft_atoi(const char *str);

char	**ft_free_str_array(char ***str_array, size_t size);

void	ft_memcpy(void *src, size_t src_len, void *dest);

#endif