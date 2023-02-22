/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:57:43 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/22 22:03:22 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src);

int main()
{
	char *testValues[] = {
		"abc",
		"Hello World!",
	};

	char* cp = NULL;
	for (int i = 0; i < 2; i++)
	{
		cp = ft_strdup(testValues[i]);
		printf("Copy of %s : \n%s\n", testValues[i], cp);
		free(cp);
	}
	

	return 0;
}
