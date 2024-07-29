/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:54:40 by ychng             #+#    #+#             */
/*   Updated: 2024/07/29 23:55:01 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

void	draw_column_wall(t_main *main, int x, t_column_wall *params, int i)
{
	t_image		*image;
	t_image		*texture;
	int			y;

	image = &main->minilibx.image;
	texture = &main->minilibx.texture;
	params->x_offset = find_x_offset(main, i);
	y = params->start_y;
	while (y < params->end_y)
	{
		params->y_offset = find_y_offset(main, y);
		pixel_put(image, x, y, pixel_get( \
			texture, params->x_offset, params->y_offset
			));
		y++;
	}
}
