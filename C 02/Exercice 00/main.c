/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:20:55 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/13 19:53:25 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char	*ft_strcpy(char *dest, char *src);

int main()
{
	char* srcStr1 = "abcd";
	char* desStr1 = malloc(5);
	printf("ft_strcpy : %s -> %s -> %s\n", srcStr1, ft_strcpy(desStr1, srcStr1), desStr1);
	strcpy(desStr1, srcStr1);
	printf("strcpy : %s -> %s\n", srcStr1, desStr1);

	printf("\n");

	char* srcStr2 = "a";
	char* desStr2 = malloc(2);
	printf("ft_strcpy : %s -> %s -> %s\n", srcStr2, ft_strcpy(desStr2, srcStr2), desStr2);
	printf("strcpy : %s -> %s -> %s\n", srcStr2, strcpy(desStr2, srcStr2), desStr2);

	printf("\n");

	char* srcStr3 = "";
	char desStr3[3] = "ab";
	printf("ft_strcpy : %s -> %s -> %s\n", srcStr3, ft_strcpy(desStr3, srcStr3), desStr3);
	printf("strcpy : %s -> %s -> %s\n", srcStr3, strcpy(desStr3, srcStr3), desStr3);

	return 0;
}
