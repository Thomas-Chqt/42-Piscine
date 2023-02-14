/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:24:25 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/14 12:25:23 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_str_is_numeric(char *str);

int main()
{
	char* a = "1234";
	printf("Test with '%s' 	-> %d\n", a, ft_str_is_numeric(a));

	a = "abcd";
	printf("Test with '%s' 	-> %d\n", a, ft_str_is_numeric(a));

	a = "12A34";
	printf("Test with '%s' 	-> %d\n", a, ft_str_is_numeric(a));

	a = "!#$f4ffFA";
	printf("Test with '%s' 	-> %d\n", a, ft_str_is_numeric(a));

	a = "";
	printf("Test with '%s' 		-> %d\n", a, ft_str_is_numeric(a));
	return 0;
}