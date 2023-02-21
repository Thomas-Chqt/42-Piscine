/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:39:53 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/21 22:54:30 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	ft_find_next_prime(int nb);

int main()
{
	int testValues[] = { 0, 1, 2, 3, 5, 7, 11, 18, 20, 28, (INT_MAX - 100), INT_MIN };
	
	for (int i = 0; i < 12; i++)
	{
		printf("%d next -> %d\n", testValues[i], ft_find_next_prime(testValues[i]));
	}
	
	return 0;
}
