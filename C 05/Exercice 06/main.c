/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:52:38 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/21 22:35:30 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<limits.h>

int ft_is_prime(int nb);

int main()
{
	int testValues[] = { 0, 1, 2, 3, 5, 7, 11, 18, 20, 28, INT_MAX, INT_MIN };
	
	for (int i = 0; i < 12; i++)
	{
		printf("test %d -> %d\n", testValues[i], ft_is_prime(testValues[i]));
	}
	

	return 0;
}
