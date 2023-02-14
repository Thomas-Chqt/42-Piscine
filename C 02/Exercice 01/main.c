/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:44:54 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/14 11:49:39 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

char* getMemHex(void* startPtr, int len);
char* decToHex(uint8_t decimal);


int main()
{
	char* src  = "ABCD";
	char* dest = malloc(6);
	memset(dest, 0xAA, 6);
	printf("src  	: %s\n", getMemHex(src , 5));
	printf("dest 	: %s\n", getMemHex(dest, 6));
	printf("ft_strncpy 5 ...\n");
	printf("return  : %s\n", getMemHex(ft_strncpy(dest, src, 5), 5));
	printf("src  	: %s\n", getMemHex(src , 5));
	printf("dest 	: %s\n", getMemHex(dest, 6));

	printf("\n");

	memset(dest, 0xAA, 6);
	printf("src  	: %s\n", getMemHex(src , 5));
	printf("dest 	: %s\n", getMemHex(dest, 6));
	printf("ft_strncpy 3 ...\n");
	printf("return  : %s\n", getMemHex(ft_strncpy(dest, src, 3), 5));
	printf("src  	: %s\n", getMemHex(src , 5));
	printf("dest 	: %s\n", getMemHex(dest, 6));

	printf("\n");

	src  = "AB";
	memset(dest, 0xAA, 6);
	printf("src  	: %s\n", getMemHex(src , 3));
	printf("dest 	: %s\n", getMemHex(dest, 6));
	printf("ft_strncpy 5 ...\n");
	printf("return  : %s\n", getMemHex(ft_strncpy(dest, src, 5), 5));
	printf("src  	: %s\n", getMemHex(src , 3));
	printf("dest 	: %s\n", getMemHex(dest, 6));

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