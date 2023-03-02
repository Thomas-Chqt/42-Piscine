/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commande_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:16:50 by mayyamad          #+#    #+#             */
/*   Updated: 2023/02/26 22:58:53 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_commande_line.h"

char	*ft_get_dict(int argc, char *argv[])
{
	if (argc == 2)
		return ("numbers.dict");
	if (argc == 3)
		return (argv[1]);
	return (NULL);
}

ssize_t	ft_get_number(int argc, char *argv[])
{
	ssize_t	return_value;

	if (argc < 2 || argc > 3)
		return (-1);
	if (argc == 3)
		return_value = ft_atoi(argv[2]);
	else
		return_value = ft_atoi(argv[1]);
	if (return_value == ATOI_ERROR || return_value < 0
		|| return_value > UINT_MAX)
		return (-1);
	return (return_value);
}

int	ft_print_number(unsigned int num, char *dict_path)
{
	char	*converted_number;
	size_t	converted_number_len;

	converted_number = ft_convert_num(num, dict_path);
	if (converted_number == NULL)
		return (-1);
	converted_number_len = ft_strlen(converted_number);
	write(1, converted_number, converted_number_len);
	write(1, "\n", 1);
	free(converted_number);
	return (0);
}
