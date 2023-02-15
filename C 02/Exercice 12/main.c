/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:58:43 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/15 10:03:25 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	void* startPtr = malloc(42);
	memset(startPtr, 0xAA, 25);

	printf("%d Bytes from %p\n",25, startPtr);
	return 0;
}
