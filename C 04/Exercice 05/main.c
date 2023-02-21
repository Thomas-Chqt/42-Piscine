/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:11:33 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/21 16:59:56 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <limits.h>

typedef struct s_Test Test;
struct s_Test
{
	char *nbr;
	char *base;
};

int	ft_atoi_base(char *str, char *base);

int main()
{
	Test tests[] = {
		{"AA", "0123456789ABCDEF"},
		{"AA", ""},
		{"AA", "012345678 9ABCDEF"},
		{"AA", "012345678+9ABCDEF"},
		{"AA", "012345678-9ABCDEF"},
		{"AA", "0123456789AACDEF"},
		{"FF", "0123456789ABCDEF"},
		{"10101010", "01"},
		{"nvn", "poneyvif"},
		{"", "0123456789ABCDEF"},
		{"255", "0123456789"},
		{"-255", "0123456789"},
		{"+nvnab", "poneyvif"},
		{"    ---+--+AAab567", "0123456789ABCDEF"},
		{"--+--+1234ab567", "0123456789"},
		{"     1234ab567", "0123456789ABCDEF"},
		{"abc", "0123456789ABCDEF"},
	};

	for (int i = 0; i < 17; i++)
	{
		printf("Test with %s in base %s :\n", tests[i].nbr, tests[i].base);
		printf("%d\n\n", ft_atoi_base(tests[i].nbr, tests[i].base));
	}
	return 0;
}


