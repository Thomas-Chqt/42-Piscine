/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:16:00 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/15 00:17:36 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	ft_putstr_non_printable(char *str);

int main()
{
	char* str = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(str);
	printf("\n");

	str = "Ab23\34\10";
	ft_putstr_non_printable(str);
	printf("\n");

	str = "Ab23\r\t";
	ft_putstr_non_printable(str);
	printf("\n");


	return 0;
}
