/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:44:54 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/14 10:12:11 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

void printMem(void* startPtr, int len);

int main()
{
	char* srcStr1 = "abcd"; 
	char* desStr1 = malloc(5);
	memset(desStr1, 0xAA, 5);
	char* res1 = ft_strncpy(desStr1, srcStr1, 5);

	char* srcStr2 = "ab"; 
	char* desStr2 = malloc(5);
	memset(desStr2, 0xAA, 5);
	char* res2 = ft_strncpy(desStr2, srcStr2, 5);

	char* srcStr3 = "ab"; 
	char* desStr3 = malloc(5);
	memset(desStr3, 0xAA, 5);
	char* res3 = ft_strncpy(desStr3, srcStr3, 2);

	char* srcStr4 = "abcd"; 
	char* desStr4 = malloc(5);
	memset(desStr4, 0xAA, 5);
	char* res4 = ft_strncpy(desStr4, srcStr4, 2);

	printMem(desStr4, 5);

	return 0;
}


void printMem(void* startPtr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%02x", *((uint8_t*)startPtr+i));
	}
	
}