/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:28:09 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/02 22:58:45 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_do_op(int a, char op, int b)
{
	t_func_ptr	op_array[128];

	op_array['+'] = &ft_plus;
	op_array['-'] = &ft_minus;
	op_array['/'] = &ft_divide;
	op_array['*'] = &ft_multiply;
	op_array['%'] = &ft_modulo;
	return (op_array[(int)op](a, b));
}
