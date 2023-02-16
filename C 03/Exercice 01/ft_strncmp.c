/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:13:22 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/16 22:37:15 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n);

// int	ft_strncmp(char *s1, char *s2, unsigned int n)
// {
// 	unsigned int	i;

// 	if (s1[0] == '\0')
// 		return (s1[0] - s2[0]);
// 	i = 0;
// 	while (i < n)
// 	{
// 		if (s1[i] == '\0')
// 			return (0);
// 		if (s1[i] != s2[i])
// 			return (s1[i] - s2[i]);
// 		i++;
// 	}
// 	return (0);
// }

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	check_n;

	check_n = 0;
	while ((*s1 != '\0' || *s2 != '\0') && check_n < n)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		check_n++;
	}
	return (0);
}
