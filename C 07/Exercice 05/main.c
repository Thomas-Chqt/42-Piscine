/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:59:36 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/23 18:28:02 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);
void	printArray(char** array);

typedef struct s_testValue
{
	char *str;
	char *charset;
} TestValue;

int main()
{
	TestValue testValues[] = {
		{ "a/b/c/d", "/" },
		{ "ab/cd/ef/gh", "/" },
		{ "a/b c/d", "/ " },
		{ "a / b - - c / d", "-/ " },
		{ "", "-/" },
		{ "a/b/c/d", "" }
	};

	
	char** splitedArray;
	
	for (int i = 0; i < 6; i++)
	{
		printf("Split '%s' by '%s'\n", testValues[i].str, testValues[i].charset);
		splitedArray = ft_split(testValues[i].str, testValues[i].charset);
		if (splitedArray == NULL)
		{
			printf("(null)");
		}
		else
		{
			printArray(splitedArray);
			for (int i = 0; splitedArray[i] != 0; i++)
			{
				free(splitedArray[i]);
			}
			free(splitedArray);
		}
	}
	return 0;
}


void printArray(char** array)
{
	if (array[0] == NULL)
	{
		printf("{ }\n\n");
		return;
	}
	
	printf("{ ");
	printf("%s", array[0]);
	for (int i = 1; array[i] != 0; i++)
	{
		printf(", %s", array[i]);
	}
	printf(" }\n\n");
}