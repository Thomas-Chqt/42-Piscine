/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:06:04 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/26 23:24:52 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

# include <stdlib.h>

typedef struct s_entry
{
	unsigned int	nbr;
	char			*str;
}	t_entry;

void	ft_free_splided_line_array(char ****splited_lines, size_t size);
void	ft_free_entry_array(t_entry **array, size_t size);
void	ft_free_str_arr(char ***str_array, size_t size);

#endif