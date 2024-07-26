/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_wall_strips.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:31:08 by ychng             #+#    #+#             */
/*   Updated: 2024/07/26 19:06:47 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_rect(t_main *main, int wall_strip_height, int i)
{
	int	height;
	int	width;
	int	start_y;
	int	start_x;
	int	y;
	int	x;	

	height = wall_strip_height;
	width = main->raycast.wall_strip_width;
	start_y = (main->mapdata.m_height / 2) - (height / 2);
	start_x = i * width;
	y = start_y;
	while (y < (start_y + height))
	{
		x = start_x;
		while (x < (start_x + width))
		{
			if (!is_within_win_bounds(main, x, y))
				break ;
			pixel_put(&main->minilibx.image, x, y, rgb(255, 0, 0));
			x++;
		}
		y++;
	}
}

void	draw_wall_strip(t_main *main, int i)
{
	double	distance_projection_plane;
	int		wall_strip_height;

	distance_projection_plane = (main->mapdata.m_width / 2) / tan(main->raycast.fov_angle / 2);
	wall_strip_height = (TILE_SIZE / main->raycast.rays[i].distance) * distance_projection_plane;
	draw_rect(main, wall_strip_height, i);
}

void	cast_wall_strips(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->raycast.num_of_rays)
	{
		draw_wall_strip(main, i);
		i++;
	}
}
