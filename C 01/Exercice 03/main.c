/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:02:18 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/12 15:26:38 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int main()
{
	int divResult = 0;
	int divModulo = 0;

	printf("Test with 42 / 40 :\n");
	ft_div_mod(42, 40, &divResult, &divModulo);
	printf("Result : %d\nModulo : %d\n\n", divResult, divModulo);

	printf("Test with 42 / 0 :\n");
	ft_div_mod(42, 0, &divResult, &divModulo);
	printf("Result : %d\nModulo : %d\n\n", divResult, divModulo);

	printf("Test with 42 / -42 :\n");
	ft_div_mod(42, -42, &divResult, &divModulo);
	printf("Result : %d\nModulo : %d\n\n", divResult, divModulo);

	printf("Test with -42 / -42 :\n");
	ft_div_mod(-42, -42, &divResult, &divModulo);
	printf("Result : %d\nModulo : %d\n\n", divResult, divModulo);

	printf("Test with -42 / -40 :\n");
	ft_div_mod(-42, -40, &divResult, &divModulo);
	printf("Result : %d\nModulo : %d\n\n", divResult, divModulo);

	return 0;
}
