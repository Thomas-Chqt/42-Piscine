/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_codes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:28:51 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/27 22:36:19 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_CODES_H
# define ERROR_CODES_H

# include <errno.h>

//error that can be return
# define OPEN_ERROR -1111
# define CLOSE_ERROR -2222
# define READ_ERROR -3333
# define ATOI_ERROR -4444
# define HEADER_ERROR -5555
# define BODY_ERROR -6666

//error only used with errno
# define END_OF_FILE 1111
# define ALLOCATION_ERROR 2222

#endif