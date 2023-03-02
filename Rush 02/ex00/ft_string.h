/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:47:14 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/26 23:38:42 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "error_codes.h"

size_t	ft_strlen(const char *str);

//allocate memory for a copy of 'str' and do the copy
//null teminate the string
//need to free the memory
char	*ft_strdup(const char *src);

//allocate memory for a copy of 'str' of size 'len' and do the copy
//null teminate the string
//need to free the memory
char	*ft_strdupl(const char *src, size_t len);

//create a null terminated string from a byte buffer
//return NULL and set errno for any error
//allocate new memory for the string and free the buffer
//need to free the memory
char	*ft_creat_str(uint8_t **buffer, size_t len);

//split str at the first ':' and return 2 string
//return NULL for allocation error
//free str an allocate splits
//need to free the memory
char	**ft_split_str(char **str);

//remove all spaces and non printable charactere
//before and after the string
//return 0 if no error
//return ALLOCATION_ERROR for malloc fail
//may reallocate memory
int		ft_normalise_str(char **str);
int		ft_normalise_str_array(char ***str, size_t size);

//return true if the caractere is not printable
bool	ft_is_removeable(char c);

//return ATOI_ERROR for error
ssize_t	ft_atoi(char *str);

//return true if contain non printable charactere
bool	ft_is_bad_str(char *str);

char	*ft_strcat(char *dest, char *src);

#endif