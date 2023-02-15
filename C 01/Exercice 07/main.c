/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:28:31 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/15 20:40:29 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	ft_rev_int_tab(int *tab, int size);

void	ft_print_tab(int *tab, int size);

int main()
{
	int tab1[] = { 1, 2, 3, 3 };
	int tab2[] = { 1, 2, 3, 4, 5 };
	int tab4[] = { -1, -2, -3, -4, -5 };
	int tab5[] = {};

	printf("Test with : ");
	ft_print_tab(tab1, 4);
	printf("\n");
	printf("Reversing...\n");
	ft_rev_int_tab(tab1, 4);
	ft_print_tab(tab1, 4);
	printf("\n");
	
	printf("Test with : ");
	ft_print_tab(tab2, 5);
	printf("\n");
	printf("Reversing...\n");
	ft_rev_int_tab(tab2, 5);
	ft_print_tab(tab2, 5);
	printf("\n");

	printf("Test with : ");
	ft_print_tab(tab4, 5);
	printf("\n");
	printf("Reversing...\n");
	ft_rev_int_tab(tab4, 5);
	ft_print_tab(tab4, 5);
	printf("\n");

	printf("Test with : ");
	ft_print_tab(tab5, 0);
	printf("\n");
	printf("Reversing...\n");
	ft_rev_int_tab(tab5, 0);
	ft_print_tab(tab5, 0);
	printf("\n");

	return 0;
}

void	ft_print_tab(int *tab, int size)
{	
	printf("{ %d", tab[0]);
	for (int i = 1; i < size; i++)
	{
		printf(", %d", tab[i]);
	}
	printf(" }");
}