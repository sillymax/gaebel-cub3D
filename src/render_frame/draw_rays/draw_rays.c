/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:21:38 by ychng             #+#    #+#             */
/*   Updated: 2024/07/27 16:21:55 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_ray(t_main *main, int i)
{
	t_player	*player;
	t_ray		*ray;
	t_points	points;

	player = &main->player;
	ray = &main->raycast.rays[i];
	points.x0 = player->center_x * M_SCALE_FACTOR;
	points.y0 = player->center_y * M_SCALE_FACTOR;
	points.x1 = ray->wall_hit_x * M_SCALE_FACTOR;
	points.y1 = ray->wall_hit_y * M_SCALE_FACTOR;
	dda(main, &points);
}

void	draw_rays(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->raycast.num_of_rays)
	{
		draw_ray(main, i);
		i++;
	}
}
