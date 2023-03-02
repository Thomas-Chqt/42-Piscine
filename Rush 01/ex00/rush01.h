/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:09:49 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/19 23:07:05 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

# include "setup.h"
# include "constraint.h"

typedef struct s_grid		t_grid;
typedef struct s_constraint	t_constraint;

extern unsigned int			g_grid_size;
extern unsigned int			**g_all_combinaisons;
extern unsigned int			g_all_combinaisons_count;
extern t_grid				g_grid;
extern unsigned int			***g_possible_rows;
extern unsigned int			*g_possible_rows_count;

struct s_grid
{
	unsigned int			**boxes;
	t_constraint			*h_constraint;
	t_constraint			*v_constraint;
};

unsigned int	*ft_get_collum(unsigned int **boxes, unsigned int index);
int				ft_set_possible_rows(void);
int				ft_insert_in_grid(unsigned int pos, unsigned int *values);
int				ft_setup_rush(unsigned int grid_size);
bool			ft_try_combinaison(unsigned int *tryed_combi);

#endif