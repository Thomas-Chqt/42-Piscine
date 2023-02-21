/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:29:54 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/21 21:32:48 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index);

int main()
{
	int testValues[] = {7, 10, 14, 0, 1, -1, -2};

	for (int i = 0; i < 7; i++)
	{
		printf("Index %d -> %d\n", testValues[i], ft_fibonacci(testValues[i]));
	}
	return 0;
}
