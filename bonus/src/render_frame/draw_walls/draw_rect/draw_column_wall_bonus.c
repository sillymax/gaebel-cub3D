/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column_wall_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:54:40 by ychng             #+#    #+#             */
/*   Updated: 2024/08/08 12:17:00 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	pixel_get(t_main *main, t_image *texture, int x, int y)
{
	int		y_bytes;
	int		x_bytes;
	char	*dst;
	int		new_dst;

	y_bytes = y * texture->stride;
	x_bytes = x * (texture->bpp / 8);
	dst = texture->addr + y_bytes + x_bytes;
	new_dst = add_shader(main, dst);
	return (new_dst);
}

int	add_shader(t_main *main, char *dst)
{
	int		color;
	float	brightness_factor;
	int		r;
	int		g;
	int		b;

	color = *(int *)dst;
	brightness_factor = 1.0 / (1.0 + main->raycast.correct_wall_dist * 0.02);
	if (brightness_factor > 1.0)
		brightness_factor = 1.0;
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r = (int)(r * brightness_factor);
	g = (int)(g * brightness_factor);
	b = (int)(b * brightness_factor);
	color = (r << 16) | (g << 8) | b;
	return (color);
}

int	find_x_offset(t_main *main, int i)
{
	t_ray	*ray;

	ray = &main->raycast.rays[i];
	if (ray->was_hit_vert)
		return ((int)ray->wall_hit_y % TILE_SIZE);
	return ((int)ray->wall_hit_x % TILE_SIZE);
}

int	find_y_offset(t_main *main, int y)
{
	t_raycast	*raycast;
	t_mapdata	*mapdata;
	int			wall_strip_height;
	int			dist_from_top;

	raycast = &main->raycast;
	mapdata = &main->mapdata;
	wall_strip_height = raycast->wall_strip_height;
	dist_from_top = y + (wall_strip_height / 2) - (mapdata->m_height / 2);
	return (dist_from_top * (TILE_SIZE / (double)wall_strip_height));
}

t_image	*find_direction_texture(t_main *main, int i)
{
	t_ray	*ray;

	ray = &main->raycast.rays[i];
	if (ray->hit_direction == NORTH)
		return (&main->minilibx.texture[NORTH]);
	else if (ray->hit_direction == SOUTH)
		return (&main->minilibx.texture[SOUTH]);
	else if (ray->hit_direction == EAST)
		return (&main->minilibx.texture[EAST]);
	return (&main->minilibx.texture[WEST]);
}
