/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:50:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/20 21:57:17 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<limits.h>

void ft_putnbr(int nb);

int main()
{
	int test_nbr[] = { 42, -42, 0, 402, INT_MAX, INT_MIN };

	for (int i = 0; i < 6; i++)
	{
		printf("Test with : %d\n", test_nbr[i]);
		ft_putnbr(test_nbr[i]);
		printf("\n\n");
	}
}
