/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:03:13 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/16 16:09:42 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);


int main()
{
    char *str1 = "Hello, world!";
    char *str2 = "Hello, world!";
    printf("'%s' and '%s' : \nft_strncmp 13 -> %d | strncmp 13 -> %d\n\n", str1, str2, ft_strncmp(str1, str2, 13), strncmp(str1, str2, 13));

	str1 = "Hello, world!";
    str2 = "Hello, everyone!";
	printf("'%s' and '%s' : \nft_strncmp 5 -> %d | strncmp 5 -> %d\n\n", str1, str2, ft_strncmp(str1, str2, 5), strncmp(str1, str2, 5));

	str1 = "";
    str2 = "";
	printf("'%s' and '%s' : \nft_strncmp 5 -> %d | strncmp 5 -> %d\n\n", str1, str2, ft_strncmp(str1, str2, 5), strncmp(str1, str2, 5));

	str1 = "Hello, world!";
    str2 = "Hello,\x15\x11\xffveryone!";
	printf("'%s' and '%s' : \nft_strncmp 17 -> %d | strncmp 17 -> %d\n\n", str1, str2, ft_strncmp(str1, str2, 17), strncmp(str1, str2, 17));

	str1 = "Hello, world!";
    str2 = "Hello, everyone!";
	printf("'%s' and '%s' : \nft_strncmp 0 -> %d | strncmp 0 -> %d\n\n", str1, str2, ft_strncmp(str1, str2, 0), strncmp(str1, str2, 0));

	str1 = "hello world";
	str2 = "hello";
	printf("'%s' and '%s' : \nft_strncmp 5 -> %d | strncmp 5 -> %d\n\n", str1, str2, ft_strncmp(str1, str2, 5), strncmp(str1, str2, 5));

	str1 = "";
	str2 = "hello world";
	printf("'%s' and '%s' : \nft_strncmp 5 -> %d | strncmp 5 -> %d\n\n", str1, str2, ft_strncmp(str1, str2, 5), strncmp(str1, str2, 5));

	str1 = "hello world";
	str2 = "";
	printf("'%s' and '%s' : \nft_strncmp 5 -> %d | strncmp 5 -> %d\n\n", str1, str2, ft_strncmp(str1, str2, 5), strncmp(str1, str2, 5));

	str1 = "hello world";
	str2 = "";
	printf("'%s' and '%s' : \nft_strncmp 0 -> %d | strncmp 0 -> %d\n\n", str1, str2, ft_strncmp(str1, str2, 0), strncmp(str1, str2, 0));

    return 0;
}