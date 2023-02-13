/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:29:31 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/12 15:48:39 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int main()
{
	int a = 0;
	int b = 0;

	printf("Test with 42 / 40 :\n");
	a = 42;
	b = 40;
	ft_ultimate_div_mod(&a, &b);
	printf("Result : %d\nModulo : %d\n\n", a, b);

	printf("Test with 42 / 0 :\n");
	a = 42;
	b = 0;
	ft_ultimate_div_mod(&a, &b);
	printf("Result : %d\nModulo : %d\n\n", a, b);

	printf("Test with 42 / -42 :\n");
	a = 42;
	b = -42;
	ft_ultimate_div_mod(&a, &b);
	printf("Result : %d\nModulo : %d\n\n", a, b);

	printf("Test with -42 / -42 :\n");
	a = -42;
	b = -42;
	ft_ultimate_div_mod(&a, &b);
	printf("Result : %d\nModulo : %d\n\n", a, b);

	printf("Test with -42 / -40 :\n");
	a = -42;
	b = -40;
	ft_ultimate_div_mod(&a, &b);
	printf("Result : %d\nModulo : %d\n\n", a, b);

	return 0;
}
