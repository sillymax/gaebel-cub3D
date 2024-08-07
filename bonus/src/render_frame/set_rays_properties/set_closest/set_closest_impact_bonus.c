/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_closest_impact_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 20:25:35 by ychng             #+#    #+#             */
/*   Updated: 2024/08/07 17:30:22 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

double	distance_between_points(t_points *points)
{
	long long	delta_x;
	long long	delta_y;

	delta_x = points->x1 - (long long)points->x0;
	delta_y = points->y1 - (long long)points->y0;
	return (sqrt(pow(delta_x, 2) + pow(delta_y, 2)));
}

double	calc_distance(t_player *player, t_impact *impact)
{
	t_points	points;

	if (impact->found_wall_hit)
	{
		points.x0 = player->center_x;
		points.y0 = player->center_y;
		points.x1 = impact->wall_hit_x;
		points.y1 = impact->wall_hit_y;
		return (distance_between_points(&points));
	}
	return (INT_MAX);
}

double	find_closest_distance(t_main *main, int i)
{
	t_ray		*ray;
	t_player	*player;
	double		horz_hit_distance;
	double		vert_hit_distance;

	ray = &main->raycast.rays[i];
	player = &main->player;
	horz_hit_distance = calc_distance(player, &ray->horz);
	vert_hit_distance = calc_distance(player, &ray->vert);
	ray->was_hit_vert = false;
	if (horz_hit_distance < vert_hit_distance)
		return (horz_hit_distance);
	ray->was_hit_vert = true;
	return (vert_hit_distance);
}

void	set_closest_impact(t_main *main, int i)
{
	t_ray	*ray;

	ray = &main->raycast.rays[i];
	ray->distance = find_closest_distance(main, i);
	if (ray->was_hit_vert)
	{
		ray->wall_hit_x = ray->vert.wall_hit_x;
		ray->wall_hit_y = ray->vert.wall_hit_y;
	}
	else
	{
		ray->wall_hit_x = ray->horz.wall_hit_x;
		ray->wall_hit_y = ray->horz.wall_hit_y;
	}
}
