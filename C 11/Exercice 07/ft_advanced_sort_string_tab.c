/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:51:39 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/02 23:08:17 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_swap(char **a, char **b);

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	y;

	i = 0;
	while (tab[i] != NULL)
	{
		y = i + 1;
		while (tab[y] != NULL)
		{
			if (cmp(tab[i], tab[y]) > 0)
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
