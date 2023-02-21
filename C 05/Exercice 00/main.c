/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:47:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/21 17:47:23 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb);

int main()
{
	int testValues[] = { 4, 10, 1, 0, -1 -10 };

	for (int i = 0; i < 6; i++)
	{
		printf("%d! = %d", testValues[i], ft_iterative_factorial(i));
	}
	
	return 0;
}
