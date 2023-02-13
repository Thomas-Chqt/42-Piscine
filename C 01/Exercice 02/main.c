/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:36:48 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/12 14:59:58 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	ft_swap(int *a, int *b);

int	main(void)
{
	int	a = 42;
	int	b = 24;

	printf("A : %d\nB : %d\n", a, b);
	printf("swap...\n");
	ft_swap(&a,&b);
	printf("A : %d\nB : %d\n", a, b);
	return 0;
}
