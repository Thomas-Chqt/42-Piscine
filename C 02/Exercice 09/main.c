/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:27:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/14 16:21:03 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

char	*ft_strcapitalize(char *str);

int main()
{
	char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("	  %s : \n", str);
	printf("Return -> %s\n", ft_strcapitalize(str));
	printf("	  %s\n", str);

	printf("\n");

	char str2[] = "sAlut, comMent TU vas ? 42mOts Quarante-Deux; cinqUante+et+un";
	printf("	  %s : \n", str2);
	printf("Return -> %s\n", ft_strcapitalize(str2));
	printf("	  %s\n", str2);

	printf("\n");

	char str3[] = "";
	printf("	  %s : \n", str3);
	printf("Return -> %s\n", ft_strcapitalize(str3));
	printf("	  %s\n", str3);
	
	return 0;
}
