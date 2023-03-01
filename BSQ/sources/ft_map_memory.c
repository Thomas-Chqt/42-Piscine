/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:39:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/01 12:38:20 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_back.h"

void	ft_free_matrix(t_box ***matrix, size_t height)
{
	size_t	y;

	y = 0;
	while (y < height)
		free((*matrix)[y++]);
	free(*matrix);
	*matrix = NULL;
}
