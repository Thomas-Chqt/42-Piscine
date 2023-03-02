/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:00:12 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/19 23:19:02 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include "loop.h"
#include "print.h"
#include "arguments.h"
#include "memory.h"

int	start(int argc, char const *argv[]);

int	main(int argc, char const *argv[])
{
	if (start(argc, argv) != 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	start(int argc, char const *argv[])
{
	unsigned int	*mach_comb;
	unsigned int	i;
	ft_setup_rush(4);
	ft_allocate_global_varaiabel();
	if (ft_setup_args(argc, argv) != 0)
		return (4);
	if (ft_set_possible_rows() != 0)
		return (2);
	mach_comb = loop_on_all(g_possible_rows_count, ft_try_combinaison);
	if (mach_comb == NULL)
		return (3);
	i = 0;
	while (i < g_grid_size)
	{
		ft_insert_in_grid(i, g_possible_rows[i][mach_comb[i]]);
		i++;
	}
	print_grid();
	return (0);
}
