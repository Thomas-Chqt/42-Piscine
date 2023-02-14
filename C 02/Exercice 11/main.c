/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:16:00 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/14 19:01:20 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr_non_printable(char *str);

int main()
{
	char* str = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(str);
	return 0;
}
