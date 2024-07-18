/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vert_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:58:09 by ychng             #+#    #+#             */
/*   Updated: 2024/07/18 10:08:49 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_vert_x_intercept(t_player *player, t_ray *ray)
{
	ray->vert.x_intercept = floor(player->center_x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_facing_right)
		ray->vert.x_intercept += TILE_SIZE;
}

void	set_vert_y_intercept(t_player *player, t_ray *ray)
{
	double	delta_x;

	delta_x = ray->vert.x_intercept - player->center_x;
	ray->vert.y_intercept = player->center_y + (delta_x * tan(ray->ray_angle));
}

void	set_vert_steps_inc(t_ray *ray)
{
	ray->vert.x_step = TILE_SIZE;
	if (ray->is_facing_left)
		ray->vert.x_step *= -1;
	ray->vert.y_step = TILE_SIZE * tan(ray->ray_angle);
	if (ray->is_facing_up && ray->vert.y_step > 0)
		ray->vert.y_step *= -1;
	if (ray->is_facing_down && ray->vert.y_step < 0)
		ray->vert.y_step *= -1;
}

void	set_vert_intersection(t_main *main, int i)
{
	t_player	*player;
	t_raycast	*raycast;
	t_ray		*ray;

	player = &main->player;
	raycast = &main->raycast;
	ray = &raycast->rays[i];
	set_vert_y_intercept(player, ray);
	set_vert_x_intercept(player, ray);
	set_vert_steps_inc(ray);
}
