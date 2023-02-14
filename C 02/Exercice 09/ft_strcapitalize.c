/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:36:01 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/14 16:21:01 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);
void	ft_capitalize(char *c);
void	ft_un_capitalize(char *c);
int		ft_is_separator(char *c);

char	*ft_strcapitalize(char *str)
{
	unsigned long long	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_capitalize(str + i);
		while (ft_is_separator(str + i) == 0)
		{
			i++;
			ft_un_capitalize(str + i);
		}
		i++;
	}
	return (str);
}

//Capitalize only if possible
void	ft_capitalize(char *c)
{
	if ((*c >= 'a') && (*c <= 'z'))
	{
		*c -= 32;
	}
}

void	ft_un_capitalize(char *c)
{
	if ((*c >= 'A') && (*c <= 'Z'))
	{
		*c += 32;
	}
}

//Return 1 if c define a new word, like ' ' or '-'
int	ft_is_separator(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
	{
		return (0);
	}
	if (*c >= 'a' && *c <= 'z')
	{
		return (0);
	}
	if (*c >= '0' && *c <= '9')
	{
		return (0);
	}
	return (1);
}
