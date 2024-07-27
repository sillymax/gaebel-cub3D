/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:40:34 by ychng             #+#    #+#             */
/*   Updated: 2024/07/27 23:19:11 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	pixel_put(t_image *image, int x, int y, int color)
{
	int		y_bytes;
	int		x_bytes;
	char	*dst;

	y_bytes = y * image->stride;
	x_bytes = x * (image->bpp / 8);
	dst = image->addr + y_bytes + x_bytes; 
	*(int *)dst = color;
}

double	find_longest_side(double delta_x, double delta_y)
{
	if (fabs(delta_x) >= fabs(delta_y))
		return (fabs(delta_x));
	return (fabs(delta_y));
}

void	dda(t_main *main, t_points *points)
{
	t_dda	dda;
	int		i;
	int		color;

	dda.delta_x = points->x1 - points->x0;
	dda.delta_y = points->y1 - points->y0;
	dda.side_len = find_longest_side(dda.delta_x, dda.delta_y);
	dda.x_inc = dda.delta_x / dda.side_len;
	dda.y_inc = dda.delta_y / dda.side_len;
	dda.curr_x = points->x0;
	dda.curr_y = points->y0;
	i = 0;
	while (i < dda.side_len)
	{
		if (!is_within_win_bounds(main, dda.curr_x, dda.curr_y))
			break ;
		color = rgb(255, 0, 0);
		pixel_put(&main->minilibx.image, dda.curr_x, dda.curr_y, color);
		dda.curr_x += dda.x_inc;
		dda.curr_y += dda.y_inc;
		i++;
	}
}
