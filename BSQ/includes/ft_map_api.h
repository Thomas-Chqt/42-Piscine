/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_api.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:49:19 by tchoquet          #+#    #+#             */
/*   Updated: 2023/03/01 15:35:08 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_API_H
# define FT_MAP_API_H

# include <unistd.h>
# include "ft_file_api.h"

typedef enum e_box			t_box;
typedef struct s_map		t_map;
typedef struct s_point		t_point;
typedef struct s_solution	t_solution;

struct s_map
{
	t_file	file;
	size_t	height;
	size_t	width;
	t_box	**matrix;
	char	empty_c;
	char	obstacle_c;
	char	full_c;

};

enum e_box
{
	empty,
	obstacle,
	full,
	undefined
};

struct s_point
{
	size_t	x;
	size_t	y;
} ;

struct s_solution
{
	t_point	point;
	size_t	size;
};

//Initialize the map with the corespondig file
//check if there are no error in the file
//return 0 if no error or a error code (OPEN_ERROR, HEADER_ERROR, BODY_ERROR)
//need to use ft_deinit_map() to properly free the memory
//need to use ft_deinit_map() in case of HEADER_ERROR or BODY_ERROR
int			ft_init_map(t_map *map, const char *file_path);

//need to pass a pointer to the data buffer
//automaicaty free the data buffer
int			ft_init_map_stdin(t_map *map, char **data);

//free all the memory and close the file
int			ft_deinit_map(t_map *map);

//-----------------------------------------------------------------------//
t_box		ft_get_box_struc(t_point point, t_map *map);

t_box		ft_get_box_point(size_t x, size_t y, t_map *map);

//-----------------------------------------------------------------------//
int			ft_set_box_struc(t_point point, t_map *map, t_box box);

int			ft_set_box_point(size_t x, size_t y, t_map *map, t_box box);

//change the value in the matrix
int			ft_insert(t_solution solution, t_map *map);

void		ft_print_map(t_map *map);

t_solution	ft_get_solution(t_map *map);

#endif