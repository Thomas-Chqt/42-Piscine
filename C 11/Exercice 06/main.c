/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:48:44 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/02 22:56:54 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_sort_string_tab(char **tab);

int main(int argc, char const *argv[])
{
	char *array[] = {
		"c",
		"a",
		"b",
		NULL
	};

	ft_sort_string_tab(array);

	return 0;
}
