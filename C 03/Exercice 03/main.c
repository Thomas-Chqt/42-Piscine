/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:44:30 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/15 23:32:04 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

char* decToHex(uint8_t decimal);
char* getMemHex(void* startPtr, int len);

int main()
{
	char* s1 = malloc(5);
	memset(s1, 0xFF, 5);
	char* s2 = malloc(3);
	memset(s2, 0xFF, 5);




	memset(s1, 0xAA, 2); memset(s1 + 2, 0x0, 1);
	memset(s2, 0xBB, 2); memset(s2 + 2, 0x0, 1);

	printf("'%s' + '%s' (2) = '%s' / '%s'\n", getMemHex(s1, 5), 
			getMemHex(s2, 3), 
			getMemHex(ft_strncat(s1, s2, 2), 5),
			getMemHex(s1, 5));

	memset(s1, 0xFF, 5);
	memset(s2, 0xFF, 5);

	memset(s1, 0xAA, 2); memset(s1 + 2, 0x0, 1);
	memset(s2, 0xBB, 2); memset(s2 + 2, 0x0, 1);

	printf("'%s' + '%s' (1) = '%s' / '%s'\n", getMemHex(s1, 5), 
			getMemHex(s2, 3), 
			getMemHex(ft_strncat(s1, s2, 1), 5),
			getMemHex(s1, 5));

	memset(s1, 0xFF, 5);

	memset(s1, 0xAA, 2); memset(s1 + 2, 0x0, 1);
	memset(s2, 0x0, 5);

	printf("'%s' + '%s' (2) = '%s' / '%s'\n", getMemHex(s1, 5), 
			getMemHex(s2, 3), 
			getMemHex(ft_strncat(s1, s2, 2), 5),
			getMemHex(s1, 5));

	memset(s1, 0x0, 5);
	
	memset(s2, 0xFF, 5);
	memset(s2, 0xBB, 2); memset(s2 + 2, 0x0, 1);

	printf("'%s' + '%s' (2) = '%s' / '%s'\n", getMemHex(s1, 5), 
			getMemHex(s2, 3), 
			getMemHex(ft_strncat(s1, s2, 2), 5),
			getMemHex(s1, 5));

	return 0;
}

char* getMemHex(void* startPtr, int len)
{
	char* mem = malloc(sizeof(char) * (len * 3 - 1));
	if (mem == NULL) exit(1);
	
	char* hex = decToHex(*((u_int8_t*)startPtr));
	memcpy(mem, hex, 2);
	free(hex);
	mem[2] = ' ';
	for (int i = 1, y = 3; i < len; i++, y+=3)
	{
		hex = decToHex(*(((u_int8_t*)startPtr)+i));
		memcpy(mem + y, hex, 2);
		free(hex);
		mem[y+2]=' ';
	}
	*(mem + (len * 3 - 1)) = '\0';
	return mem;
}

char* decToHex(uint8_t decimal) 
{
	char* hexa = malloc(sizeof(char) * 3);

	hexa[0] = decimal / 16;
	hexa[1] = decimal % 16;

	for (int i = 0; i <= 1; i++)
	{
		if (hexa[i] < 10) 
		{
			hexa[i] += 48;
		}
		else 
		{
			hexa[i] += 55;
		}
	}
	hexa[2] = '\0';
	return hexa;
}