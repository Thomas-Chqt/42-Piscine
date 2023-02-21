/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:05:06 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/21 10:33:23 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str);

int main()
{
	char *testStr[] = {
		"    ---+--+1234ab567",
		"--+--+1234ab567",
		"     1234ab567",
		"-1234",
		"+1234ab",
		"+ab",
		"abc",
		"1234",
	};

	for (int i = 0; i < 8; i++)
	{
		printf("Test with : '%s'\n", testStr[i]);
		printf("atoi : %d\n\n", ft_atoi(testStr[i]));
	}
}