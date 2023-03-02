/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:09:26 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/19 22:19:29 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

unsigned int	g_grid_size;
unsigned int	**g_all_combinaisons;
unsigned int	g_all_combinaisons_count;
t_grid			g_grid;
unsigned int	***g_possible_rows;
unsigned int	*g_possible_rows_count;

unsigned int	*ft_get_collum(unsigned int **boxes, unsigned int index)
{
	unsigned int	*ret_val;
	unsigned int	i;

	ret_val = malloc(sizeof(unsigned int) * g_grid_size);
	i = 0;
	while (i < g_grid_size)
	{
		ret_val[i] = boxes[i][index];
		i++;
	}
	return (ret_val);
}

int	ft_set_possible_rows(void)
{
	unsigned int	row_nbr;
	unsigned int	comb_index;

	row_nbr = 0;
	while (row_nbr < g_grid_size)
	{
		g_possible_rows_count[row_nbr] = 0;
		comb_index = 0;
		while (comb_index < g_all_combinaisons_count)
		{	
			if (ft_is_match(g_all_combinaisons[comb_index],
					g_grid.h_constraint[row_nbr]))
			{
				g_possible_rows[row_nbr][g_possible_rows_count[row_nbr]]
					= g_all_combinaisons[comb_index];
				g_possible_rows_count[row_nbr]++;
			}
			comb_index++;
		}
		if (g_possible_rows_count[row_nbr] == 0)
			return (1);
		row_nbr++;
	}
	return (0);
}

int	ft_setup_rush(unsigned int grid_size)
{
	g_grid_size = grid_size;
	g_all_combinaisons = (unsigned int **)generate_permutations(g_grid_size);
	g_all_combinaisons_count = factorial(grid_size);
	return (0);
}

int	ft_insert_in_grid(unsigned int pos, unsigned int *boxes)
{
	unsigned int	i;

	i = 0;
	while (i < g_grid_size)
	{
		g_grid.boxes[pos][i] = boxes[i];
		i++;
	}
	return (0);
}

bool	ft_try_combinaison(unsigned int *tryed_combi)
{
	unsigned int	i;

	i = 0;
	while (i < g_grid_size)
	{
		ft_insert_in_grid(i, g_possible_rows[i][tryed_combi[i]]);
		i++;
	}
	return (ft_is_resolv());
}
