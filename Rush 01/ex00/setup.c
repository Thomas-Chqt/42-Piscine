/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:18:49 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/19 23:40:45 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

int	factorial(int n)
{
	if (n == 0)
	{
		return (1);
	}
	else
	{
		return (n * factorial(n - 1));
	}
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	permute(int **res, int *arr, int *l_r, int *index)
{
	int	i;

	if (l_r[0] == l_r[1])
	{
		i = 0;
		while (i <= l_r[1])
		{
			res[*index][i] = arr[i];
			i++;
		}
		(*index)++;
	}
	else
	{
		i = l_r[0];
		while (i <= l_r[1])
		{
			swap((arr + l_r[0]), (arr + i));
			l_r[0]++;
			permute(res, arr, l_r, index);
			swap((arr + l_r[0]), (arr + i));
			i++;
		}
	}
}

int	**generate_permutations(int n)
{
	int	**res;
	int	i;
	int	*arr;
	int	index;
	int	l_r[2];

	l_r[0] = 0;
	l_r[1] = n - 1;
	arr = malloc(sizeof(int) * n);
	i = 0;
	res = (int **) malloc(sizeof(int *) * factorial(n));
	while (i < factorial(n))
	{
		res[i] = (int *) malloc(sizeof(int) * n);
		i++;
	}
	i = 0;
	while (i < n)
	{
		arr[i] = i + 1;
		i++;
	}
	index = 0;
	permute(res, arr, l_r, &index);
	return (res);
}
