/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:11:45 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/02 16:20:35 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*output_tab;
	int	i;

	output_tab = malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		output_tab[i] = f(tab[i]);
		i++;
	}
	return (output_tab);
}
