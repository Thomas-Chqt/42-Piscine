/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:31:44 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/19 23:06:26 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	print_grid(void)
{
	char			c;
	unsigned int	i;
	unsigned int	y;

	i = 0;
	while (i < g_grid_size)
	{
		c = (char)('0' + g_grid.boxes[i][0]);
		write(1, &c, 1);
		y = 1;
		while (y < g_grid_size)
		{
			write(1, " ", 1);
			c = (char)('0' + g_grid.boxes[i][y]);
			write(1, &c, 1);
			y++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
