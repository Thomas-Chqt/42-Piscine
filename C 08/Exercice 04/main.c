/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:20:14 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/23 23:16:23 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>

struct s_stock_str *ft_strs_to_tab(int ac, char **av);
void	ft_show_tab(struct s_stock_str *par);

int main()
{
	char *av[] = {
		"abc",
		"efg",
		"",
		"\t"
	};

	t_stock_str* structArray = ft_strs_to_tab(4, av);
	structArray[1].copy[1] = ' ';
	ft_show_tab(structArray);

	return 0;
}
