/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:40:01 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/12 15:48:31 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b);

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	if (*b == 0)
	{
		*a = 0;
		*b = 0;
		return ;
	}
	temp = *a;
	*a = *a / *b;
	*b = temp % *b;
}
