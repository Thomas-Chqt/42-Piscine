/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:01:58 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/16 23:40:04 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_INT 2147483647

void	ft_sort_int_tab(int *tab, int size);
void	ft_swap(int *a, int *b);
void	ft_set_first(int *tab, int size);

/*
void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	*temp_ptr;
	int	i;
	int	y;

	if (size <= 1)
		return ;
	ft_set_first(tab, size);
	i = 0;
	while (i < size)
	{
		temp = MAX_INT;
		temp_ptr = 0;
		y = i;
		while (y < size)
		{
			if (tab[y] <= temp)
			{
				temp = tab[y];
				temp_ptr = tab + y;
			}
			y++;
		}
		ft_swap(tab + i, temp_ptr);
		i++;
	}
}
*/

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	y;

	if (size <= 1)
		return ;
	ft_set_first(tab, size);
	i = 0;
	while (i < size)
	{
		y = i;
		while (y < size)
		{
			if (tab[i] > tab[y])
				ft_swap(tab + i, tab + y);
			y++;
		}
		i++;
	}
}

void	ft_set_first(int *tab, int size)
{
	int	temp;
	int	*temp_ptr;
	int	i;

	temp = MAX_INT;
	temp_ptr = 0;
	i = 0;
	while (i < size)
	{
		if (tab[i] <= temp)
		{
			temp = tab[i];
			temp_ptr = tab + i;
		}
		i++;
	}
	ft_swap(tab, temp_ptr);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
