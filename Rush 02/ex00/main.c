/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:10:38 by mayyamad          #+#    #+#             */
/*   Updated: 2023/02/26 22:26:40 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_commande_line.h"

int	main(int argc, char *argv[])
{
	char			*dict_path;
	unsigned int	number;
	ssize_t			return_value;

	dict_path = ft_get_dict(argc, argv);
	if (dict_path == NULL)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return_value = ft_get_number(argc, argv);
	if (return_value < 0)
	{
		write(1, "Error\n", 6);
		return (2);
	}
	number = (unsigned int)return_value;
	return_value = ft_print_number(number, dict_path);
	if (return_value != 0)
	{
		write(1, "Dict Error\n", 11);
		return (return_value);
	}
	return (0);
}
