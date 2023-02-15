/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:39:12 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/15 23:46:23 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

int main () {
   char *big = "TutorialsPointTutorials";
   char *little = "Point";
   char *ret;

   ret = strstr(big, little);

   printf("The substring is: %s\n", ret);
   
   return(0);
}
