/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:48:44 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/02 23:06:50 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void 	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *));
int		ft_strcmp(char *s1, char *s2);

int main(int argc, char const *argv[])
{
	char *array[] = {
		"c",
		"a",
		"b",
		NULL
	};

	ft_advanced_sort_string_tab(array, &ft_strcmp);

	return 0;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
