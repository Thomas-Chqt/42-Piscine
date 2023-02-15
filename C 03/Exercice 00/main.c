/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:39:39 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/15 18:25:52 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);


int main()
{
    char *str1 = "Hello, world!";
    char *str2 = "Hello, world!";
    printf("'%s' and '%s' : \nft_strcmp -> %d | strcmp -> %d\n\n", str1, str2, ft_strcmp(str1, str2), strcmp(str1, str2));

	str1 = "Hello, world!";
    str2 = "Hello, everyone!";
	printf("'%s' and '%s' : \nft_strcmp -> %d | strcmp -> %d\n\n", str1, str2, ft_strcmp(str1, str2), strcmp(str1, str2));

	str1 = "";
    str2 = "";
	printf("'%s' and '%s' : \nft_strcmp -> %d | strcmp -> %d\n\n", str1, str2, ft_strcmp(str1, str2), strcmp(str1, str2));

	str1 = "Hello, world!";
    str2 = "Hello,\x15\x11\xffveryone!";
	printf("'%s' and '%s' : \nft_strcmp -> %d | strcmp -> %d\n\n", str1, str2, ft_strcmp(str1, str2), strcmp(str1, str2));

    return 0;
}


