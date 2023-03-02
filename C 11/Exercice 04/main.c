/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:35:31 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/02 19:51:51 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int));

int ft_is_bigger(int a, int b)
{
	return(a - b);
}

int main()
{
	int tab[] = { 1, 2, 3, 4, 5, 6};

	int rest = ft_is_sort(tab, 6, &ft_is_bigger);

	rest++;
	return 0;
}
