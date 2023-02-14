/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:28:51 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/14 14:29:35 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

char	*ft_strlowcase(char *str);

int main()
{
	char str[] = "ABCD";
	printf("%s : \n", str);
	printf("Return -> %s\n",ft_strlowcase(str));
	printf("Str -> %s\n", str);

	printf("\n");

	char str2[] = "abcd";
	printf("%s : \n", str2);
	printf("Return -> %s\n",ft_strlowcase(str2));
	printf("Str -> %s\n", str2);

	printf("\n");

	char str3[] = "aBcD";
	printf("%s : \n", str3);
	printf("Return -> %s\n",ft_strlowcase(str3));
	printf("Str -> %s\n", str3);

	printf("\n");

	char str4[] = "Ab23C";
	printf("%s : \n", str4);
	printf("Return -> %s\n",ft_strlowcase(str4));
	printf("Str -> %s\n", str4);

	printf("\n");

	char str5[] = "";
	printf("%s : \n", str5);
	printf("Return -> %s\n",ft_strlowcase(str5));
	printf("Str -> %s\n", str5);
	return 0;
}
