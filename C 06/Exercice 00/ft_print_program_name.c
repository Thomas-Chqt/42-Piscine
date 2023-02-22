/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:33:08 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/22 13:38:48 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char const *argv[])
{
	int	i;

	if (argc < 1)
		return (1);
	i = 0;
	while (argv[0][i])
	{
		write(1, &(argv[0][i]), 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
