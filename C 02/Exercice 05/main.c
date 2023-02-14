/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:37:57 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/14 12:39:04 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_str_is_uppercase(char *str);

int main()
{
	char* a = "ABCD";
	printf("Test with '%s' 	-> %d\n", a, ft_str_is_uppercase(a));

	a = "abcd";
	printf("Test with '%s' 	-> %d\n", a, ft_str_is_uppercase(a));

	a = "12A34";
	printf("Test with '%s' 	-> %d\n", a, ft_str_is_uppercase(a));

	a = "!#$f4ffFA";
	printf("Test with '%s' 	-> %d\n", a, ft_str_is_uppercase(a));

	a = "";
	printf("Test with '%s' 		-> %d\n", a, ft_str_is_uppercase(a));
	return 0;
}