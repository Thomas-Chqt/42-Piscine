/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:15:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/12 13:22:00 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_INT 2147483647

void	rush(int x, int y);
int		ft_get_int(char *str);
int		ft_check_arg(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	if (ft_check_arg(argc, argv) != 0)
		return (1);
	rush(ft_get_int(argv[1]), ft_get_int(argv[2]));
	return (0);
}

int	ft_get_int(char *str)
{
	int	nbr;
	int	i;

	nbr = 0;
	i = 0;
	while (str[i] != '\0')
	{
		nbr *= 10;
		if (nbr + (str[i] - 48) < nbr)
			return (MAX_INT);
		nbr += ((str[i] - 48));
		i++;
	}
	return (nbr);
}

int	ft_check_arg(int argc, char *argv[])
{
	int	i;
	int	c;

	if (argc != 3)
		return (1);
	i = 1;
	while (i < 3)
	{
		c = 0;
		while (argv[i][c] != '\0')
		{
			if ((argv[i][c] < '0') || (argv[i][c] > '9'))
				return (1);
			c++;
		}
		i++;
	}
	return (0);
}
