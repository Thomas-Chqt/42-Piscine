/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:10:31 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/22 22:32:25 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	*ft_range(int min, int max);
void printArray(int* array, int size);

typedef struct s_testValue TestValue;
struct s_testValue
{
	int min;
	int max;
};




int main()
{
	TestValue testValues[] = {
		{3, 5},
		{0, 100},
		{50, 40}
	};

	int *range = NULL;

	for (int i = 0; i < 3; i++)
	{
		printf("%d -> %d :\n", testValues[i].min, testValues[i].max);
		printArray(ft_range(testValues[i].min, testValues[i].max), )
	}
	

	return 0;
}

void printArray(int* array, int size)
{
	printf("{ ");
	if (size > 0)
	{
		printf("%d", array[0]);
	}
	for (int i = 1; i < size; i++)
	{
		printf(", %d", array[i]);
	}
	printf(" }");
}
