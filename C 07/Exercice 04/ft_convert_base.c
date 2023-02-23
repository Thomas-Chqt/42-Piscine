/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:54:35 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/23 15:46:52 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
void	ft_setnbr_base(int nbr, char *base, char **str_to_set);
int		ft_check_base(char *base);
int		ft_get_index(char c, char *base);
int		ft_strlen(char *str);
void	ft_setabnbr_base(unsigned int nbr, char *base,
			char **str_to_set, int *str_c);
int		ft_get_converted_nbr_len(int dec_nbr, char *base_to);
int		ft_recursive_power(int nb, int power);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		dec_nbr;
	char	*converted_base;

	if (ft_check_base(base_from) != 0 || ft_check_base(base_to) != 0)
		return (NULL);
	dec_nbr = ft_atoi_base(nbr, base_from);
	converted_base = malloc(sizeof(char)
			* (ft_get_converted_nbr_len(dec_nbr, base_to) + 1));
	if (converted_base == NULL)
		return (NULL);
	ft_setnbr_base(dec_nbr, base_to, &converted_base);
	return (converted_base);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nbr;
	int	i;
	int	signe;

	signe = 1;
	nbr = 0;
	if (ft_check_base(base) != 0)
		return (0);
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (ft_get_index(str[i], base) >= 0)
	{
		nbr *= ft_strlen(base);
		nbr += ft_get_index(str[i], base) % ft_strlen(base);
		i++;
	}
	return (nbr * signe);
}

void	ft_setnbr_base(int nbr, char *base, char **str_to_set)
{
	long	l_nbr;
	int		str_c;

	str_c = 0;
	l_nbr = (long)nbr;
	if (ft_check_base(base) != 0)
		return ;
	if (l_nbr < 0)
	{
		(*str_to_set)[str_c] = '-';
		str_c++;
		l_nbr *= -1;
	}
	ft_setabnbr_base((unsigned int)l_nbr, base, str_to_set, &str_c);
	(*str_to_set)[str_c] = '\0';
}

int	ft_get_converted_nbr_len(int dec_nbr, char *base_to)
{
	int	len;

	len = 1;
	while ((ft_recursive_power(ft_strlen(base_to), (len - 1)) - 1) < dec_nbr)
		len++;
	return (len);
}
