/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:17:27 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/19 22:56:37 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

int	ft_allocate_grid(void)
{
	unsigned int	i;

	i = 0;
	g_grid.boxes = malloc(sizeof(unsigned int *) * g_grid_size);
	if (g_grid.boxes == NULL)
		return (1);
	while (i < g_grid_size)
	{
		g_grid.boxes[i] = malloc(sizeof(unsigned int) * g_grid_size);
		if (g_grid.boxes[i] == NULL)
			return (2);
		i++;
	}
	g_grid.h_constraint = malloc(sizeof(t_constraint) * g_grid_size);
	if (g_grid.h_constraint == NULL)
		return (3);
	g_grid.v_constraint = malloc(sizeof(t_constraint) * g_grid_size);
	if (g_grid.v_constraint == NULL)
		return (4);
	return (0);
}

int	ft_allocate_possible_rows(void)
{
	unsigned int	i;
	unsigned int	y;

	g_possible_rows = malloc(sizeof(unsigned int **) * g_grid_size);
	if (g_possible_rows == NULL)
		return (1);
	i = 0;
	while (i < g_grid_size)
	{
		g_possible_rows[i]
			= malloc(sizeof(unsigned int *) * g_all_combinaisons_count);
		if (g_possible_rows[i] == NULL)
			return (2);
		y = 0;
		while (y < g_all_combinaisons_count)
		{
			g_possible_rows[i][y] = malloc(sizeof(unsigned int) * g_grid_size);
			if (g_possible_rows[i][y] == NULL)
				return (3);
			y++;
		}
		i++;
	}
	return (0);
}

int	ft_allocate_global_varaiabel(void)
{
	if (ft_allocate_grid() != 0)
	{
		return (1);
	}
	if (ft_allocate_possible_rows() != 0)
	{
		return (2);
	}
	g_possible_rows_count = malloc(sizeof(unsigned int) * g_grid_size);
	if (g_possible_rows_count == NULL)
	{
		return (3);
	}
	return (0);
}

int	ft_free_global_variable(void)
{
	unsigned int	i;

	i = 0;
	while (i < g_all_combinaisons_count)
	{
		free(g_all_combinaisons[i]);
		i++;
	}
	free(g_all_combinaisons);
	i = 0;
	while (i < g_grid_size)
	{
		free(g_grid.boxes[i]);
		i++;
	}
	free(g_grid.boxes);
	free(g_grid.h_constraint);
	free(g_grid.v_constraint);
	return (0);
}
