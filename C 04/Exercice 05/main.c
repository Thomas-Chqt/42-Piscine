/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:11:33 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/21 15:52:56 by tchoquet         ###   ########.fr       */
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
		{"FF", "0123456789ABCDEF"},
		{"AA", ""},
		{"AA", "012345678 9ABCDEF"},
		{"AA", "012345678+9ABCDEF"},
		{"AA", "012345678-9ABCDEF"},
		{"AA", "0123456789AACDEF"},
		{"AA", "0123456789AACDEF"},
		{"10101010", "01"},
		{"nvn", "poneyvif"},

	};

	for (int i = 0; i < 9; i++)
	{
		printf("Test with %s in base %s :\n", tests[i].nbr, tests[i].base);
		printf("%d\n\n", ft_atoi_base(tests[i].nbr, tests[i].base));
	}
	return 0;
}
