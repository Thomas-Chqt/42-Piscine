/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainEx01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:54:01 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/12 14:19:07 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	ft_ultimate_ft(int *********nbr);

int main()
{
	int nbr;
	int* ptr1 = &nbr;
	int** ptr2 = &ptr1;
	int*** ptr3 = &ptr2;
	int**** ptr4 = &ptr3;
	int***** ptr5 = &ptr4;
	int****** ptr6 = &ptr5;
	int******* ptr7 = &ptr6;
	int******** ptr8 = &ptr7;
	int********* ptr9 = &ptr8;
	ft_ultimate_ft(ptr9);

	printf("%d\n", nbr);

	return 0;
}
