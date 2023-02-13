/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:58:10 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/12 23:08:33 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int main()
{
	char dest[3] = {'\1', '\1', '\1'};
	const char* src = "abc";

	strcpy(dest, src);

	return 0;
}


char	*ft_strcpy(char *dest, char *src);

char	*ft_strcpy(char *dest, char *src)
{
	
}