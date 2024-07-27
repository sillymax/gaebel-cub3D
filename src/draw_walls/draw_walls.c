/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:31:08 by ychng             #+#    #+#             */
/*   Updated: 2024/07/27 20:22:11 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_rect_pixel(t_main *main, int i, int top_pixel_y, int bottom_pixel_y)
{
	int	start_x;
	int	x;
	int	y;

	start_x = main->raycast.wall_strip_width * i;
	x = start_x;
	while (x < (start_x + main->raycast.wall_strip_width))
	{
		y = 0;
		while (y < top_pixel_y)
		{
			pixel_put(&main->minilibx.image, x, y, rgb(105, 105, 105));
			y++;
		}
		y = top_pixel_y;
		while (y < bottom_pixel_y)
		{
			pixel_put(&main->minilibx.image, x, y, rgb(55, 55, 55));
			y++;
		}
		y = bottom_pixel_y;
		while (y < main->mapdata.m_height)
		{
			pixel_put(&main->minilibx.image, x, y, rgb(25, 25, 25));
			y++;
		}
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
	bottom_pixel_y = half_screen + (main->raycast.wall_strip_height / 2);
	draw_rect_pixel(main, i, top_pixel_y, bottom_pixel_y);
}

void	set_correct_wall_dist(t_main *main, int i)
{
	t_player	*player;
	t_raycast	*raycast;
	t_ray		*ray;

	player = &main->player;
	raycast = &main->raycast;
	ray = &raycast->rays[i];
	raycast->correct_wall_dist = \
		ray->distance * cos(ray->ray_angle - player->rotation_angle);
	if (raycast->correct_wall_dist == 0)
		raycast->correct_wall_dist = 0.1;
}

void	set_wall_strip_height(t_main *main)
{
	t_mapdata	*mapdata;
	t_raycast	*raycast;
	double		dist_proj_plane;

	mapdata = &main->mapdata;
	raycast = &main->raycast;
	dist_proj_plane = (mapdata->m_width / 2) / tan(raycast->fov_angle / 2);
	raycast->wall_strip_height = \
		(TILE_SIZE / raycast->correct_wall_dist) * dist_proj_plane;
	if (raycast->wall_strip_height > mapdata->m_height)
		raycast->wall_strip_height = mapdata->m_height;
}

void	draw_wall_strip(t_main *main, int i)
{
	set_correct_wall_dist(main, i);
	set_wall_strip_height(main);
	draw_rect(main, i);
}

void	draw_walls(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->raycast.num_of_rays)
	{
		draw_wall_strip(main, i);
		i++;
	}
}
