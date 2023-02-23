/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:04:56 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/23 13:54:16 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);
void	printArray(char** array, int size);

typedef struct s_testValue
{
	char	**strs;
	int		size;
	char	*sep;
} TestValue ;


int main()
{
	char	*strs1[] = {"a", "b", "c"};
	char	*strs2[] = {"ab", "cd", "ef"};
	char	*strs3[] = {"ab", "cd", "ef"};

	TestValue testVlaues[4] = {
		{strs1 , 3, ", "},
		{strs2 , 3, "/"},
		{strs3 , 3, ""},
		{NULL , 0, "/"}
	};

	char *joinedStr = NULL;

	for (int i = 0; i < 4; i++)
	{
		printf("Test with :\n	Size : %d\n	Strs : ", testVlaues[i].size);
		printArray(testVlaues[i].strs, testVlaues[i].size);
		printf("\n	Sep : '%s'\n", testVlaues[i].sep);
		joinedStr = ft_strjoin(testVlaues[i].size, testVlaues[i].strs, testVlaues[i].sep);
		printf("-> '%s'\n\n", joinedStr);
		free(joinedStr);
	}
	return 0;
}

void printArray(char** array, int size)
{
	printf("{ ");
	if (size > 0)
	{
		printf("%s", array[0]);
	}
	for (int i = 1; i < size; i++)
	{
		printf(", %s", array[i]);
	}
	printf(" }");
}