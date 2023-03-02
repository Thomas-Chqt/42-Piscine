/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:20:08 by tchoquet          #+#    #+#             */
/*   Updated: 2023/02/12 13:24:04 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef enum e_position	t_position;
enum e_position {
	top_left = 'A',
	top_right = 'C',
	bottom_left = 'C',
	bottom_right = 'A',
	top = 'B',
	left = 'B',
	right = 'B',
	bottom = 'B',
	middle = ' '
};

void		ft_putchar(char c);
void		rush(int x, int y);
t_position	ft_get_position(int x, int y, int max_x, int max_y);

void	rush(int x, int y)
{
	int	current_x;
	int	current_y;

	if (x < 1 || y < 1)
		return ;
	current_y = 1;
	while (current_y <= y)
	{
		current_x = 1;
		while (current_x <= x)
		{
			ft_putchar(ft_get_position(current_x, current_y, x, y));
			current_x++;
		}
		ft_putchar('\n');
		current_y++;
	}
}

t_position	ft_get_position(int x, int y, int max_x, int max_y)
{
	if ((x == 1) && (y == 1))
		return (top_left);
	if ((x == max_x) && (y == 1))
		return (top_right);
	if ((x == 1) && (y == max_y))
		return (bottom_left);
	if ((x == max_x) && (y == max_y))
		return (bottom_right);
	if (y == 1)
		return (top);
	if (x == 1)
		return (left);
	if (x == max_x)
		return (right);
	if (y == max_y)
		return (bottom);
	return (middle);
}
