/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:48:07 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/22 16:26:07 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<limits.h>

int	ft_sqrt(int nb);

int main()
{
	int testValue[] = { 9, 25, 81, -3, -9, 0, 3, 6, INT_MAX};

	for (int i = 0; i < 9; i++)
	{
		printf("sqrt(%d) = %d\n", testValue[i], ft_sqrt(testValue[i]));
	}
	return 0;
}
