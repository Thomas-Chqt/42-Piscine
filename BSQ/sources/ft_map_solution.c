/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:58:44 by aenshin           #+#    #+#             */
/*   Updated: 2023/03/01 13:26:05 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_back.h"

void	zeromap(int *map, int i, int j)
{
	int	ii;
	int	jj;

	ii = 0;
	while (ii < i)
	{
		jj = 0;
		while (jj < j)
		{
			*(map + ii * j + jj) = 0;
			jj++;
		}
		ii++;
	}
}

int	calc_min(int *dp, int y, int i, int j)
{
	int	min;

	min = *(dp + (y + 1) * i + j + 1);
	if (*(dp + (y + 1) * i + j) < min)
		min = *(dp + (y + 1) * i + j);
	if (*(dp + (y + 1) * (i + 1) + j) < min)
		min = *(dp + (y + 1) * (i + 1) + j);
	*(dp + (y + 1) * (i + 1) + j + 1) = min + 1;
	return (min);
}

void	do_dp(int *dp, int *map, t_solution *res, t_point point)
{
	int				max;
	int				min;
	ssize_t			i;
	ssize_t			j;

	max = 0;
	i = -1;
	while ((size_t)++i < point.x)
	{
		j = -1;
		while ((size_t)++j < point.y)
		{
			if (*(map + point.y * i + j) == 0)
			{
				min = calc_min(dp, point.y, i, j);
				if (min + 1 > max)
				{
					max = min + 1;
					res->size = min + 1;
					res->point.y = i - min;
					res->point.x = j - min;
				}
			}
		}
	}
}

t_solution	ft_get_solution(t_map *map)
{
	t_solution	sol;
	size_t		i;
	size_t		j;
	int			*zer0_map;

	zer0_map = malloc(sizeof(int) * map->height * map->width);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			*(zer0_map + i * map->width + j) = map->matrix[i][j];
			j++;
		}
		i++;
	}
	sol = solve(zer0_map, map->height, map->width);
	free(zer0_map);
	return (sol);
}

t_solution	solve(int *map, int x, int y)
{
	t_solution		res;
	int				*dp;
	t_point			point;

	res.point.x = 0;
	res.point.y = 0;
	res.size = 0;
	point.x = x;
	point.y = y;
	dp = malloc(sizeof(int) * (x + 1) * (y + 1));
	zeromap(dp, x + 1, y + 1);
	do_dp(dp, map, &res, point);
	free(dp);
	return (res);
}
