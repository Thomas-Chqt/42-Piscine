/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:58:43 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/15 12:41:45 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_print_memory(void *addr, unsigned int size);
/*
int main()
{
	void* startPtr = malloc(42);
	memset(startPtr, 0xAA, 20);
	memset(startPtr + 20, 0xBB, 20);
	memset(startPtr + 40, 0xCC, 2);

	printf("%d Bytes from %p\n",42, startPtr);
	ft_print_memory(startPtr, 42);
	return 0;
}
*/

int main()
{
    char *str1 = "Hello World!";
    printf("=== Test 1 ===\n");
    ft_print_memory(str1, 13);

    char *str2 = "This string has some non-printable characters: \x00\x01\x1F\x7F";
    printf("\n=== Test 2 ===\n");
    ft_print_memory(str2, 51);

    char str3[8];
    for (int i = 0; i < 8; i++)
    {
        str3[i] = (char)(i * 16 + i);
    }
    printf("\n=== Test 3 ===\n");
    ft_print_memory(str3, 6);

    int num = 2147483647;
    printf("\n=== Test 4 ===\n");
    ft_print_memory(&num, sizeof(num));

    char *ptr = NULL;
    printf("\n=== Test 5 ===\n");
    ft_print_memory(ptr, 0);

    return 0;
}