/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_num.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:54:29 by mayyamad          #+#    #+#             */
/*   Updated: 2023/02/26 23:17:48 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_NUM_H
# define CONVERT_NUM_H

#include "ft_dict_file.h"

char			*put_into_char(char **str, int len);
char			*ft_convert_num(unsigned int num, char *dict_path);
int				count_len_thou(int num, int len);
int				count_len(unsigned int num);
int				if_num_less_thou(unsigned int *a, unsigned int num, int i);
void			put_thou(unsigned int *a, int g_count, int i);
unsigned int	*ft_convert_num_int(unsigned int *a,
					unsigned int num, int g_count, int i);

#endif