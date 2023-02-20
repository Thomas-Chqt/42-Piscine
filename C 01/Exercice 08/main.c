/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:02:05 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/20 17:06:29 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_INT 2147483647
#define MIN_INT -2147483648

#include<stdio.h>

void	ft_sort_int_tab(int *tab, int size);

void	ft_print_tab(int *tab, int size);

int main()
{
	int tab1[] = { 3, 5, 1, 6 };
	int tab2[] = { 4, 7, -2, 6, 1 };
	int tab3[] = { 1, 1, 4, 4, 3 };
	int tab4[] = { -1, -6, -6, -4, -4 };
	int tab5[] = { MAX_INT, 0, 0, 0, MIN_INT };
	int tab6[] = {};
	int tab7[] = { 0 };

	printf("Test with : ");
	ft_print_tab(tab1, 4);
	printf("\n");
	printf("Sorting...\n");
	ft_sort_int_tab(tab1, 4);
	ft_print_tab(tab1, 4);
	printf("\n");

	printf("Test with : ");
	ft_print_tab(tab2, 5);
	printf("\n");
	printf("Sorting...\n");
	ft_sort_int_tab(tab2, 5);
	ft_print_tab(tab2, 5);
	printf("\n");

	printf("Test with : ");
	ft_print_tab(tab3, 5);
	printf("\n");
	printf("Sorting...\n");
	ft_sort_int_tab(tab3, 5);
	ft_print_tab(tab3, 5);
	printf("\n");

	printf("Test with : ");
	ft_print_tab(tab4, 5);
	printf("\n");
	printf("Sorting...\n");
	ft_sort_int_tab(tab4, 5);
	ft_print_tab(tab4, 5);
	printf("\n");

	printf("Test with : ");
	ft_print_tab(tab5, 5);
	printf("\n");
	printf("Sorting...\n");
	ft_sort_int_tab(tab5, 5);
	ft_print_tab(tab5, 5);
	printf("\n");

	printf("Test with : ");
	ft_print_tab(tab6, 0);
	printf("\n");
	printf("Sorting...\n");
	ft_sort_int_tab(tab6, 0);
	ft_print_tab(tab6, 0);
	printf("\n");

	printf("Test with : ");
	ft_print_tab(tab7, 1);
	printf("\n");
	printf("Sorting...\n");
	ft_sort_int_tab(tab7, 1);
	ft_print_tab(tab7, 1);
	printf("\n");

	return 0;
}

void	ft_print_tab(int *tab, int size)
{
	if (size <= 0)
	{
		printf("{ }");
		return;
	}
	printf("{ %d", tab[0]);
	for (int i = 1; i < size; i++)
	{
		printf(", %d", tab[i]);
	}
	printf(" }");
}