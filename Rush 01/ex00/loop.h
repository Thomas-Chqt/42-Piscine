/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:56:39 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/19 23:05:54 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H

# include "rush01.h"

bool			is_equal(unsigned int *array1, unsigned int *array2);

void			add_one(unsigned int **array, unsigned int *endArray);

unsigned int	*loop_on_all(unsigned int *endArray,
					bool (*fun)(unsigned int *arry));

#endif