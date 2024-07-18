/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_horz_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:54:53 by ychng             #+#    #+#             */
/*   Updated: 2024/07/18 09:55:15 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_horz_y_intercept(t_player *player, t_ray *ray)
{
	ray->horz.y_intercept = floor(player->center_y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_facing_down)
		ray->horz.y_intercept += TILE_SIZE;
}

void	set_horz_x_intercept(t_player *player, t_ray *ray)
{
	double	delta_y;

	delta_y = ray->horz.y_intercept - player->center_y;
	ray->horz.x_intercept = player->center_x + (delta_y / tan(ray->ray_angle));
}

void	set_horz_steps_inc(t_ray *ray)
{
	ray->horz.y_step = TILE_SIZE;
	if (ray->is_facing_up)
		ray->horz.y_step *= -1;
	ray->horz.x_step = TILE_SIZE / tan(ray->ray_angle);
	if (ray->is_facing_left && ray->horz.x_step > 0)
		ray->horz.x_step *= -1;
	if (ray->is_facing_right && ray->horz.x_step < 0)
		ray->horz.x_step *= -1;
}

void	set_horz_intersection(t_main *main, int i)
{
	t_player	*player;
	t_raycast	*raycast;
	t_ray		*ray;

	player = &main->player;
	raycast = &main->raycast;
	ray = &raycast->rays[i];
	set_horz_y_intercept(player, ray);
	set_horz_x_intercept(player, ray);
	set_horz_steps_inc(ray);
}
