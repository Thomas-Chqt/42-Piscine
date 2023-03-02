/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constraint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:39:30 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/19 22:18:33 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTRAINT_H
# define CONSTRAINT_H

# include "rush01.h"

typedef struct s_constraint	t_constraint;

struct s_constraint
{
	unsigned int	left_top;
	unsigned int	right_bottom;
};

bool	ft_is_match(unsigned int *boxes, t_constraint constraint);
bool	ft_is_resolv(void);

#endif