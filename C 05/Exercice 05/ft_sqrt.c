/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:43:45 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/22 16:26:05 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned long	i;
	unsigned long 	long_nb;

	if (nb <= 0)
		return (0);
	i = 1;
	long_nb = (unsigned long)nb;
	while ((i * i) <= long_nb)
	{
		if ((i * i) == long_nb)
			return ((int)i);
		i++;
	}
	return (0);
}
