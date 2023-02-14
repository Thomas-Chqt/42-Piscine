/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:59:38 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/14 12:22:29 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_str_is_alpha(char *str);

int main()
{
	char* a = "ABCD";
	printf("Test with '%s' 	-> %d\n", a, ft_str_is_alpha(a));

	a = "abcd";
	printf("Test with '%s' 	-> %d\n", a, ft_str_is_alpha(a));

	a = "1234";
	printf("Test with '%s'	-> %d\n", a, ft_str_is_alpha(a));

	a = "AB2CD";
	printf("Test with '%s' 	-> %d\n", a, ft_str_is_alpha(a));

	a = "!#$f4ffFA";
	printf("Test with '%s' 	-> %d\n", a, ft_str_is_alpha(a));

	a = "";
	printf("Test with '%s' 		-> %d\n", a, ft_str_is_alpha(a));
	return 0;
}