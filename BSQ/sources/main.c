/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 04:41:30 by aenshin           #+#    #+#             */
/*   Updated: 2023/03/01 22:40:42 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_api.h"

// __attribute__((destructor))
// void    destructor(void)
// {
//     system("leaks -q bsq 1>&2");
// }

int	ft_resolve_stdin(void)
{
	char		*map_stdin;
	t_map		map;
	t_solution	sol;

	map_stdin = ft_read_stdin();
	if (map_stdin == NULL)
	{
		write(STDERR_FILENO, "map error\n", 10);
	}
	else if (ft_init_map_stdin(&map, &map_stdin) != 0)
	{
		write(STDERR_FILENO, "map error\n", 10);
	}
	else
	{
		sol = ft_get_solution(&map);
		if (sol.size > 0)
			ft_insert(sol, &map);
		ft_print_map(&map);
	}
	ft_deinit_map(&map);
	return (0);
}

int	ft_resolve_arg(int argc, char *argv[])
{
	t_map		map;
	t_solution	sol;
	int			i;

	i = 2;
	while (i < argc)
	{
		write(1, "\n", 1);
		if (ft_init_map(&map, argv[i]) != 0)
			write(STDERR_FILENO, "map error\n", 10);
		else
		{
			sol = ft_get_solution(&map);
			if (sol.size > 0)
				ft_insert(sol, &map);
			ft_print_map(&map);
		}
		ft_deinit_map(&map);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_map		map;
	t_solution	sol;

	if (argc < 2)
	{
		return (ft_resolve_stdin());
	}
	else
	{
		if (ft_init_map(&map, argv[1]) != 0)
			write(STDERR_FILENO, "map error\n", 10);
		else
		{
			sol = ft_get_solution(&map);
			if (sol.size > 0)
				ft_insert(sol, &map);
			ft_print_map(&map);
		}
		ft_deinit_map(&map);
		return (ft_resolve_arg(argc, argv));
	}
}
