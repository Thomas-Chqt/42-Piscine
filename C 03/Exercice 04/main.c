/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:39:12 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/16 21:41:02 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

char	*ft_strstr(char *str, char *to_find);


int main () {
   char *big = "ABCD";
   char *little = "CD";

   printf("Serch '%s' in '%s' (ft_strstr) -> return '%s'\n", little, big, ft_strstr(big, little));
   printf("Serch '%s' in '%s' (strstr)	 -> return '%s'\n\n", little, big, strstr(big, little));

   little = "AB";

   printf("Serch '%s' in '%s' (ft_strstr) -> return '%s'\n", little, big, ft_strstr(big, little));
   printf("Serch '%s' in '%s' (strstr)	 -> return '%s'\n\n", little, big, strstr(big, little));

	little = "DE";

   printf("Serch '%s' in '%s' (ft_strstr) -> return '%s'\n", little, big, ft_strstr(big, little));
   printf("Serch '%s' in '%s' (strstr)	 -> return '%s'\n\n", little, big, strstr(big, little));

   big = "";
   little = "AB";

   printf("Serch '%s' in '%s' (ft_strstr)	 -> return '%s'\n", little, big, ft_strstr(big, little));
   printf("Serch '%s' in '%s' (strstr) 	 -> return '%s'\n\n", little, big, strstr(big, little));

   big = "ABCD";
   little = "";

   printf("Serch '%s' in '%s' (ft_strstr)	 -> return '%s'\n", little, big, ft_strstr(big, little));
   printf("Serch '%s' in '%s' (strstr)	 -> return '%s'\n\n", little, big, strstr(big, little));

   big = "";
   little = "";

   printf("Serch '%s' in '%s' (ft_strstr)	 -> return '%s'\n", little, big, ft_strstr(big, little));
   printf("Serch '%s' in '%s' (strstr)		 -> return '%s'\n\n", little, big, strstr(big, little));
   
   big = "A";
   little = "ABC";

   printf("Serch '%s' in '%s' (ft_strstr)	-> return '%s'\n", little, big, ft_strstr(big, little));
   printf("Serch '%s' in '%s' (strstr)	-> return '%s'\n\n", little, big, strstr(big, little));

	big = "ABCDABD";
   	little = "ABD";

   printf("Serch '%s' in '%s' (ft_strstr)	-> return '%s'\n", little, big, ft_strstr(big, little));
   printf("Serch '%s' in '%s' (strstr)	-> return '%s'\n\n", little, big, strstr(big, little));
   

   return(0);
}
