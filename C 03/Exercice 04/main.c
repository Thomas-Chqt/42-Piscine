/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:39:12 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/16 10:27:19 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

char	*ft_strstr(char *str, char *to_find);

int main () {
   char *big = "ABCD";
   char *little = "CD";

   printf("Serch %s in %s -> return %s\n", little, big, ft_strstr(big, little));

   little = "AB";

   printf("Serch %s in %s -> return %s\n", little, big, ft_strstr(big, little));

	little = "DE";

   printf("Serch %s in %s -> return %s\n", little, big, ft_strstr(big, little));

   big = "";
   little = "AB";

   printf("Serch %s in %s -> return %s\n", little, big, ft_strstr(big, little));
   
   return(0);
}
