/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_horz_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:54:53 by ychng             #+#    #+#             */
/*   Updated: 2024/07/24 03:39:53 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	is_close_to(double value, double target, double epsilon)
{
	return (fabs(value - target) < epsilon);
}

void	set_horz_y_intercept(t_player *player, t_ray *ray)
{
	if (is_close_to(ray->ray_angle, 0, EPSILON) || \
		is_close_to(ray->ray_angle, PI, EPSILON) || \
		is_close_to(ray->ray_angle, PI * 2, EPSILON))
        ray->horz.y_intercept = player->center_y;
	else
	{
		ray->horz.y_intercept = floor(player->center_y / TILE_SIZE) * TILE_SIZE;
		if (ray->is_facing_down)
			ray->horz.y_intercept += TILE_SIZE;
	}
}

void	set_horz_x_intercept(t_player *player, t_ray *ray)
{
	double	delta_y;

	if (is_close_to(ray->ray_angle, 0, EPSILON) || \
		is_close_to(ray->ray_angle, PI * 2, EPSILON))
		ray->horz.x_intercept = W_WIDTH;
	else if (is_close_to(ray->ray_angle, PI, EPSILON))
		ray->horz.x_intercept = 0;
	else if (is_close_to(ray->ray_angle, PI * 0.5, EPSILON) || \
			(is_close_to(ray->ray_angle, PI * 1.5, EPSILON)))
		ray->horz.x_intercept = player->center_x;
	else
	{
		delta_y = ray->horz.y_intercept - player->center_y;
		ray->horz.x_intercept = player->center_x + (delta_y / tan(ray->ray_angle));
	}
}

void	set_horz_steps_inc(t_ray *ray)
{
	ray->horz.y_step = TILE_SIZE;
	if (ray->is_facing_up)
		ray->horz.y_step *= -1;
	if (is_close_to(ray->ray_angle, 0, EPSILON) || \
		is_close_to(ray->ray_angle, PI, EPSILON) || \
		is_close_to(ray->ray_angle, PI * 2, EPSILON))
		ray->horz.x_step = TILE_SIZE;
	else if (is_close_to(ray->ray_angle, PI * 0.5, EPSILON) || \
			is_close_to(ray->ray_angle, PI * 1.5, EPSILON))
		ray->horz.x_step = 0;
	else
		ray->horz.x_step = TILE_SIZE / tan(ray->ray_angle);
	if ((ray->is_facing_left && ray->horz.x_step > 0) || \
		(ray->is_facing_right && ray->horz.x_step < 0))
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
