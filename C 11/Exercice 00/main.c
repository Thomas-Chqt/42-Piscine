/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:04:11 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/02 16:06:39 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void(*f)(int));
void	ft_putnbr(int nb);

int main()
{
	int array[] = {1, 2, 3, 4, 5, 6};

	ft_foreach(array, 6, &ft_putnbr);

	return 0;
}
