/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_back.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:05:57 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/01 18:46:17 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_BACK_H
# define FT_MAP_BACK_H

# include "ft_map_api.h"

//return 0 for no error
//return HEADER_ERROR for error
int			ft_parse_header(char *first_line, t_map *map);

//return 0 for no error
//return HEADER_ERROR for error
int			ft_read_header(t_map *map);
int			ft_read_header_stdin(t_map *map, char **lines);

//return 0 for no error
//return BODY_ERROR for error
int			ft_parse_body(char **lines, size_t lines_count, t_map *map);

//return 0 for no error
//return BODY_ERROR for error
int			ft_read_body(t_map *map);
int			ft_read_body_stdin(t_map *map, char **lines, size_t	lines_count);

//return true if the line contain other thant the headers caracteres
bool		ft_is_valid_line(char *line, t_map *map);

//convert a char to a box_type enum based on the values in the map
//retun undefined when not able to convert
//should not happend if the map has pass the ft_read_body function
t_box		ft_char_to_box(char c, t_map *map);

//convert les lines and insert in the matrix
//allocate the matrix
//return 0 when no error
//need to free the memory
int			ft_setup_matrix(char **lines, t_map *map);
void		ft_free_matrix(t_box ***matrix, size_t height);

void		ft_put_box(t_box box, t_map *map);

//solve the map
t_solution	solve(int *map, int x, int y);

#endif