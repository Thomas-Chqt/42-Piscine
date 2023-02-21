/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:47:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/21 19:57:47 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb);

int	main()
{
	int testValues[] = {1, 2, 3, 4, 5, -10, 0 };

	for (int i = 0; i < 7; i++)
	{
		printf("%d! = %d\n", testValues[i], ft_iterative_factorial(testValues[i]));
	}
	return 0;
}
