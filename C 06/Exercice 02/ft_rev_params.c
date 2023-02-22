/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:36:51 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/22 15:20:33 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_arg(char *arg);
void	ft_swap(char **a, char **b);
int	ft_strcmp(char *s1, char *s2);

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
		i++;
		ft_print_arg(argv[i]);
	}
}

void	ft_print_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		write(1, &arg[i], 1);
		i++;
	}
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