/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:17:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/02 16:20:30 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int *ft_map(int *tab, int length, int(*f)(int));

int add_one(int n)
{
	return n + 1;
}

int main(int argc, char const *argv[])
{
	int	array[] = {1, 2, 3, 4};
	int *newArray = ft_map(array, 4, &add_one);
	return 0;
}
