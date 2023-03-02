/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:24:54 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/02 19:26:17 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_count_if(char **tab, int length, int (*f)(char*));

int ft_strlen(char *str)
{
	int res = (int)strlen(str);
	return (res);
}

int main()
{
	char *array[] = {
		"",
		"",
		""
	};

	int res = ft_count_if(array, 3, &ft_strlen);

	printf("%d\n", res);

	return 0;
}

