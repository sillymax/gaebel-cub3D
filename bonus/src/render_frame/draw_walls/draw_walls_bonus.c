/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:31:08 by ychng             #+#    #+#             */
/*   Updated: 2024/08/07 17:30:14 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

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
