/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:57:17 by ychng             #+#    #+#             */
/*   Updated: 2024/08/08 12:17:05 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_column_wall(t_main *main, int x, t_column_wall *params, int i)
{
	t_image		*image;
	t_image		*texture;
	int			y;

	image = &main->minilibx.image;
	texture = find_direction_texture(main, i);
	params->x_offset = find_x_offset(main, i);
	y = params->start_y;
	while (y < params->end_y)
	{
		params->y_offset = find_y_offset(main, y);
		pixel_put(image, x, y, pixel_get(main, texture, \
		params->x_offset, params->y_offset));
		y++;
	}
}

void	draw_column(t_main *main, int x, t_column_wall *params, int color)
{
	t_image	*image;
	int		y;

	image = &main->minilibx.image;
	y = params->start_y;
	while (y < params->end_y)
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
		params.start_y = 0;
		params.end_y = top_pixel_y;
		draw_column(main, x, &params, find_color(main->mapinfo.ceilingcolor));
		params.start_y = top_pixel_y;
		params.end_y = bottom_pixel_y;
		draw_column_wall(main, x, &params, i);
		params.start_y = bottom_pixel_y;
		params.end_y = main->mapdata.m_height;
		draw_column(main, x, &params, find_color(main->mapinfo.floorcolor));
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
