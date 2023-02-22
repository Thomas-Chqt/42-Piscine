/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:36:51 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/22 19:08:24 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	y;

	if (argc < 2)
		return (1);
	i = argc - 1;
	while (i > 0)
	{
		y = 0;
		while (argv[i][y])
		{
			write(1, &argv[i][y], 1);
			y++;
		}
		write(1, "\n", 1);
		i--;;
	}
}