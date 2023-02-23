/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:30:08 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/23 11:57:09 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);
void printArray(int* array, unsigned long size);

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
		{50, 40},
		{3, 3},
		{-30, -15},
	};

	int *range = NULL;

	for (int i = 0; i < 5; i++)
	{
		printf("%d -> %d :\n", testValues[i].min, testValues[i].max);
		int size = ft_ultimate_range(&range, testValues[i].min, testValues[i].max);
		if (range == NULL)
		{
			printf("Size : %d\n", size);
			printf("(null)\n\n");
		}			
		else
		{
			printf("Size : %d\n", size);
			printArray(range, (long)(testValues[i].max) - (long)(testValues[i].min));
		}
		free(range);
	}
	

	return 0;
}

void printArray(int* array, unsigned long size)
{
	printf("{ ");
	if (size > 0)
	{
		printf("%d", array[0]);
	}
	for (unsigned long i = 1; i < size; i++)
	{
		printf(", %d", array[i]);
	}
	printf(" }\n\n");
}
