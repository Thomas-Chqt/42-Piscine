/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:40:12 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/22 18:56:32 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char **a, char **b);
int		ft_strcmp(char *s1, char *s2);
void	ft_print_arg(char *arg);

int	main(int argc, char *argv[])
{
	int	i;
	int	y;

	if (argc < 2)
		return (1);
	i = 1;
	while (i < argc)
	{
		y = i + 1;
		while (y < argc)
		{
			if (ft_strcmp(argv[i], argv[y]) > 0)
			{
				ft_swap(&(argv[i]), &(argv[y]));
			}
			y++;
		}
		ft_print_arg(argv[i]);
		i++;
	}
	return (0);
}

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_print_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		write(1, arg + i, 1);
		i++;
	}
	write(1, "\n", 1);
}
