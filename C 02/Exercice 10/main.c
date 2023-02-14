/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:38:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/14 17:51:33 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

char* getMemHex(void* startPtr, int len);
char* decToHex(uint8_t decimal);


int main()
{
	char* src  = "ABCD";
	char* dest = malloc(6);
	memset(dest, 0xAA, 6);
	printf("src  	: %s\n", getMemHex(src , 5));
	printf("dest 	: %s\n", getMemHex(dest, 6));
	printf("ft_strlcpy 5 ...\n");
	printf("return  : %d\n", ft_strlcpy(dest, src, 5));
	printf("src  	: %s\n", getMemHex(src , 5));
	printf("dest 	: %s\n", getMemHex(dest, 6));

	printf("\n");

	memset(dest, 0xAA, 6);
	printf("src  	: %s\n", getMemHex(src , 5));
	printf("dest 	: %s\n", getMemHex(dest, 6));
	printf("ft_strlcpy 3 ...\n");
	printf("return  : %d\n", ft_strlcpy(dest, src, 3));
	printf("src  	: %s\n", getMemHex(src , 5));
	printf("dest 	: %s\n", getMemHex(dest, 6));

	printf("\n");

	src  = "AB";
	memset(dest, 0xAA, 6);
	printf("src  	: %s\n", getMemHex(src , 3));
	printf("dest 	: %s\n", getMemHex(dest, 6));
	printf("ft_strlcpy 5 ...\n");
	printf("return  : %d\n", ft_strlcpy(dest, src, 5));
	printf("src  	: %s\n", getMemHex(src , 3));
	printf("dest 	: %s\n", getMemHex(dest, 6));

	printf("\n");

	src  = "";
	memset(dest, 0xAA, 6);
	printf("src  	: %s\n", getMemHex(src , 0));
	printf("dest 	: %s\n", getMemHex(dest, 6));
	printf("ft_strlcpy 5 ...\n");
	printf("return  : %d\n", ft_strlcpy(dest, src, 5));
	printf("src  	: %s\n", getMemHex(src , 0));
	printf("dest 	: %s\n", getMemHex(dest, 6));

	printf("\n");

	src  = "ABCD";
	memset(dest, 0xAA, 6);
	printf("src  	: %s\n", getMemHex(src , 5));
	printf("dest 	: %s\n", getMemHex(dest, 6));
	printf("ft_strlcpy 0 ...\n");
	printf("return  : %d\n", ft_strlcpy(dest, src, 0));
	printf("src  	: %s\n", getMemHex(src , 5));
	printf("dest 	: %s\n", getMemHex(dest, 6));

	return 0;
}


char* getMemHex(void* startPtr, int len)
{
	if (len <= 0 ) return "";
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