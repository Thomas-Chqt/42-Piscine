/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:09:14 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/21 14:16:29 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

typedef struct s_Test Test;
struct s_Test
{
	int decNbr;
	char *base;
};


void	ft_putnbr_base(int nbr, char *base);

int main()
{
	Test tests[] = {
		{170, "0123456789ABCDEF"},
		{170, ""},
		{170, "012345678 9ABCDEF"},
		{170, "012345678+9ABCDEF"},
		{170, "012345678-9ABCDEF"},
		{170, "0123456789AACDEF"},
		{170, "01"},
		{170, "poneyvif"},
		{-170, "0123456789ABCDEF"},
		{-170, "01"},
		{-170, "poneyvif"},
		{170, "0123456789ABCDEF"},
		{170, "01"},
		{INT_MAX, "0123456789ABCDEF"},
		{INT_MIN, "0123456789ABCDEF"},
		{INT_MIN, "01"},
	};

	for (int i = 0; i < 15; i++)
	{
		printf("Test with %d in base %s :\n", tests[i].decNbr, tests[i].base);
		ft_putnbr_base(tests[i].decNbr, tests[i].base);
		printf("\n\n");
	}
	return 0;
}
