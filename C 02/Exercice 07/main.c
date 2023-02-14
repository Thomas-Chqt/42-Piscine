/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:08:38 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/14 14:25:20 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

char	*ft_strupcase(char *str);

int main()
{
	char str[] = "abcd";
	printf("%s : \n", str);
	printf("Return -> %s\n",ft_strupcase(str));
	printf("Str -> %s\n", str);

	printf("\n");

	char str2[] = "ABCD";
	printf("%s : \n", str2);
	printf("Return -> %s\n",ft_strupcase(str2));
	printf("Str -> %s\n", str2);

	printf("\n");

	char str3[] = "AbCd";
	printf("%s : \n", str3);
	printf("Return -> %s\n",ft_strupcase(str3));
	printf("Str -> %s\n", str3);

	printf("\n");

	char str4[] = "aB23c";
	printf("%s : \n", str4);
	printf("Return -> %s\n",ft_strupcase(str4));
	printf("Str -> %s\n", str4);

	printf("\n");

	char str5[] = "";
	printf("%s : \n", str5);
	printf("Return -> %s\n",ft_strupcase(str5));
	printf("Str -> %s\n", str5);
	return 0;
}
