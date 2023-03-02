/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:56:39 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/19 23:42:13 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>


int factorial(int n);

void swap(int *a, int *b);

void permute(int **res, int *arr, int *l_r, int *index);

int** generate_permutations(int n);