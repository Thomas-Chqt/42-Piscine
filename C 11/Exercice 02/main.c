/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:23:27 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/02 19:20:29 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_any(char **tab, int (*f)(char*));

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
		"f",
		NULL
	};

	int res = ft_any(array, &ft_strlen);

	printf("%d\n", res);

	return 0;
}

