/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:31:08 by ychng             #+#    #+#             */
/*   Updated: 2024/07/29 15:29:42 by ychng            ###   ########.fr       */
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

int	pixel_get(t_image *texture, int x, int y)
{
	int		y_bytes;
	int		x_bytes;
	char	*dst;

	y_bytes = y * texture->stride;
	x_bytes = x * (texture->bpp / 8);
	dst = texture->addr + y_bytes + x_bytes; 
	return (*(int *)dst);
}

void	draw_column_wall(t_main *main, int x, int start_y, int end_y)
{
	t_raycast	*raycast;
	t_image		*image;
	t_image		*texture;
	int			y;
	int			dist_from_top;

	raycast = &main->raycast;
	image = &main->minilibx.image;
	texture = &main->minilibx.texture;
	y = start_y;
	while (y < end_y)
	{
		dist_from_top = \
			y + (raycast->wall_strip_height / 2) - (main->mapdata.m_height / 2);
		main->texture.y_offset = \
			dist_from_top * (TILE_SIZE / (float)raycast->wall_strip_height);
		pixel_put(image, x, y, \
			pixel_get(texture, main->texture.x_offset, main->texture.y_offset));
		y++;
	}
}

void	draw_rect_pixel(t_main *main, int i, int top_pixel_y, \
			int bottom_pixel_y)
{
	t_ray	*ray;
	int		start_x;
	int		x;

	ray = &main->raycast.rays[i];
	start_x = main->raycast.wall_strip_width * i;
	x = start_x;
	while (x < (start_x + main->raycast.wall_strip_width))
	{
		draw_column(main, x, 0, top_pixel_y, \
			find_color(main->mapinfo.ceilingcolor));
		if (ray->was_hit_vert)
			main->texture.x_offset = (int)ray->wall_hit_y % TILE_SIZE;
		else
			main->texture.x_offset = (int)ray->wall_hit_x % TILE_SIZE;
		draw_column_wall(main, x, top_pixel_y, bottom_pixel_y);
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
	// if (raycast->wall_strip_height > mapdata->m_height)
	// 	raycast->wall_strip_height = mapdata->m_height;
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
