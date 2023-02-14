/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:32:09 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/14 12:33:52 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_str_is_lowercase(char *str);

int main()
{
	char* a = "abcd";
	printf("Test with '%s' 	-> %d\n", a, ft_str_is_lowercase(a));

	a = "ABCD";
	printf("Test with '%s' 	-> %d\n", a, ft_str_is_lowercase(a));

	a = "12a34";
	printf("Test with '%s' 	-> %d\n", a, ft_str_is_lowercase(a));

	a = "!#$f4ffFA";
	printf("Test with '%s' 	-> %d\n", a, ft_str_is_lowercase(a));

	a = "";
	printf("Test with '%s' 		-> %d\n", a, ft_str_is_lowercase(a));
	return 0;
}