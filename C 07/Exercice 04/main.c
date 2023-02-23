/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:32:39 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/23 15:50:17 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

typedef struct s_testValue
{
	char *nbr;
	char *base_from;
	char *base_to;
} TestValue;


int main()
{
	TestValue testValues[] = {
		{"255",					"0123456789", 			"0123456789ABCDEF"},
		{"FF",					"0123456789ABCDEF", 	"0123456789"},
		{"AA",					"0123456789ABCDEF", 	"01"},
		{"AA",					"0123456789ABCDEF", 	"poneyvif"},
		{"AA",					"0123456789ABCDEF", 	"0123456789ABCDEF"},
		{"170",					"0123456789", 			"0123456789"},
		{"0",					"0123456789", 			"0123456789ABCDEF"},
		{"AA",					"012345678 9ABCDEF",	"0123456789"},
		{"AA",					"012345678+9ABCDEF",	"0123456789"},
		{"AA",					"012345678-9ABCDEF", 	"0123456789"},
		{"AA",					"0123456789AACDEF", 	"0123456789"},
		{"    ---+--+AAab567",	"0123456789ABCDEF", 	"0123456789"},
		{"--+--+1234ab567",		"0123456789", 			"0123456789ABCDEF"},
		{"     1234ab567",		"0123456789", 			"0123456789ABCDEF"},
		{"abc",					"0123456789",			"0123456789ABCDEF"}
	};

	char* convertedNbr = NULL;

	for (int i = 0; i < 14; i++)
	{
		convertedNbr = ft_convert_base(testValues[i].nbr, testValues[i].base_from, testValues[i].base_to);
		if (convertedNbr != NULL)
		{
			printf("Convert '%s'	from base '%s'	to base '%s' :	'%s'\n", testValues[i].nbr, testValues[i].base_from, testValues[i].base_to, convertedNbr);
			free(convertedNbr);
		}
		else
			printf("Convert '%s'	from base '%s'	to base '%s' :	(null)\n", testValues[i].nbr, testValues[i].base_from, testValues[i].base_to);
	}
	

	return 0;
}
