/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:57:17 by ychng             #+#    #+#             */
/*   Updated: 2024/07/29 23:57:38 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_column(t_main *main, int x, int start_y, int end_y, int color)
{
	t_image	*image;
	int		y;

	image = &main->minilibx.image;
	y = start_y;
	while (y < end_y)
	{
		pixel_put(image, x, y, color);
		y++;
	}
}

void	draw_rect_pixel(t_main *main, int i, int top_pixel_y, \
			int bottom_pixel_y)
{
	t_column_wall	params;
	int				start_x;
	int				x;

	params = (t_column_wall){0};
	start_x = main->raycast.wall_strip_width * i;
	x = start_x;
	while (x < (start_x + main->raycast.wall_strip_width))
	{
		draw_column(main, x, 0, top_pixel_y, \
			find_color(main->mapinfo.ceilingcolor));
		params.start_y = top_pixel_y;
		params.end_y = bottom_pixel_y;
		draw_column_wall(main, x, &params, i);
		draw_column(main, x, bottom_pixel_y, main->mapdata.m_height, \
			find_color(main->mapinfo.floorcolor));
		x++;
	}
}

void	draw_rect(t_main *main, int i)
{
	int	half_screen;
	int	top_pixel_y;
	int	bottom_pixel_y;

	half_screen = (main->mapdata.m_height / 2);
	top_pixel_y = half_screen - (main->raycast.wall_strip_height / 2);
	if (top_pixel_y < 0)
		top_pixel_y = 0;
	bottom_pixel_y = half_screen + (main->raycast.wall_strip_height / 2);
	if (bottom_pixel_y > main->mapdata.m_height)
		bottom_pixel_y = main->mapdata.m_height;
	draw_rect_pixel(main, i, top_pixel_y, bottom_pixel_y);
}
