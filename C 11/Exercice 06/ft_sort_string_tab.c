/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:51:39 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/02 22:57:32 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strcmp(char *s1, char *s2);
void	ft_swap(char **a, char **b);

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	y;

	i = 0;
	while (tab[i] != NULL)
	{
		y = i + 1;
		while (tab[y] != NULL)
		{
			if (ft_strcmp(tab[i], tab[y]) > 0)
			{
				ft_swap(&(tab[i]), &(tab[y]));
			}
			y++;
		}
		i++;
	}
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
