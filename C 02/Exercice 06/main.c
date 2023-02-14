/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:56:30 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/14 14:01:02 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_str_is_printable(char *str);

int main()
{
	char* a = "ABCD";
	printf("Test with '%s' 	-> %d\n", a, ft_str_is_printable(a));

	a = "\3\3";
	printf("Test with '%s' 		-> %d\n", a, ft_str_is_printable(a));

	a = "12\3a34";
	printf("Test with '%s' 	-> %d\n", a, ft_str_is_printable(a));

	a = "\3A\3\3";
	printf("Test with '%s' 		-> %d\n", a, ft_str_is_printable(a));

	a = "";
	printf("Test with '%s' 		-> %d\n", a, ft_str_is_printable(a));
	return 0;
}