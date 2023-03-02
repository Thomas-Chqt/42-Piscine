/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commande_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:11:21 by mayyamad          #+#    #+#             */
/*   Updated: 2023/02/26 22:58:57 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMMANDE_LINE_H
# define FT_COMMANDE_LINE_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "ft_string.h"
#include "ft_convert_num.h"

//return the dict in the args or NULL if error
char		*ft_get_dict(int argc, char *argv[]);

//return the number int the args or -1 if error
ssize_t		ft_get_number(int argc, char *argv[]);

int			ft_print_number(unsigned int num, char *dict_path);

#endif