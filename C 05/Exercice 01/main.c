/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:30:21 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/22 12:05:06 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb);

int	main()
{
	int testValues[] = { 1, 2, 3, 4, 5, -10, 0 };

	for (int i = 0; i < 7; i++)
	{
		printf("%d! = %d\n", testValues[i], ft_recursive_factorial(testValues[i]));
	}
	return 0;
}