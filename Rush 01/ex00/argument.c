/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:45:43 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/19 23:07:47 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arguments.h"

int	ft_setup_args(int argc, char const *argv[])
{
	unsigned int	i;

	if ((unsigned int)argc != (g_grid_size * 4 + 1))
		return (1);
	i = 0;
	while (i < g_grid_size)
	{
		g_grid.v_constraint[i].left_top = argv[i + 1][0] - '0';
		g_grid.v_constraint[i].right_bottom
			= argv[i + g_grid_size + 1][0] - '0';
		g_grid.h_constraint[i].left_top
			= argv[i + 2 * g_grid_size + 1][0] - '0';
		g_grid.h_constraint[i].right_bottom
			= argv[i + 3 * g_grid_size + 1][0] - '0';
		i++;
	}
	return (0);
}
