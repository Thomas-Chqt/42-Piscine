/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:27:54 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/22 11:40:42 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int ft_is_safe(char *grid, int new_q_index, char new_q_pos);
int ft_recurse(char *grid, int index);

int	ft_ten_queens_puzzle(void)
{
	char grid[10];
	return (ft_recurse(grid, 0));
}

int ft_is_safe(char *grid, int new_q_index, char new_q_pos)
{
	int i;

	i = new_q_index - 1;
	while (i >= 0)
	{
		if (grid[i] == new_q_pos)
			return (0);
		if (grid[i] == new_q_pos - (new_q_index - i))
			return (0);
		if (grid[i] == new_q_pos + (new_q_index - i))
			return (0);
		i--;
	}
	return (1);
}

int ft_recurse(char *grid, int index)
{
	char	i;
	static int	solution_count = 0;

	if (index >= 10)
	{
		write(1, grid, 10);
		write(1, "\n", 1);
		solution_count++;
	}
	i = '0';
	while (i <= '9')
	{
		if (ft_is_safe(grid, index, i))
		{
			grid[index] = i;
			ft_recurse(grid, index + 1);
		}
		i++;
	}
	return (solution_count);
}

