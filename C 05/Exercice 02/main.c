/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:45:57 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/21 21:02:20 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_testValue TestValue;
struct s_testValue
{
	int nb;
	int power;
};

int	ft_iterative_power(int nb, int power);

int main()
{
	TestValue testValues[] = {
		{2, 2},
		{3, 2},
		{3, 3},
		{0, 3},
		{5, 0},
		{0, 0},
		{5, -3},
	};

	for (int i = 0; i < 7; i++)
	{
		printf("%d power %d = %d\n", testValues[i].nb, testValues[i].power, ft_iterative_power(testValues[i].nb, testValues[i].power));
	}
	return 0;
}
