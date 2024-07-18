/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 06:09:53 by ychng             #+#    #+#             */
/*   Updated: 2024/07/17 17:01:15by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_rays(t_main *main)
{
	int			i;
	t_points	points;
	t_ray		*ray;

	i = 0;
	while (i < main->raycast.num_of_rays)
	{
		ray = &main->raycast.rays[i];
		points.x0 = main->player.center_x;
		points.y0 = main->player.center_y;
		points.x1 = points.x0 + cos(ray->ray_angle) * LINE_LENGTH;
		points.y1 = points.y0 + sin(ray->ray_angle) * LINE_LENGTH;
		dda(main, &points);
		i++;
	}
}

void	set_rays_angle(t_main *main)
{
	int		columnid;
	t_ray	*ray;
	double	start_angle;
	double	angle_inc;
	double	ray_angle;

	columnid = 0;
	start_angle = main->player.rotation_angle - (main->raycast.fov_angle / 2);
	ray_angle = normalize_angle(start_angle);
	while (columnid < main->raycast.num_of_rays)
	{
		ray = &main->raycast.rays[columnid];
		ray->columnid = columnid;
		ray->ray_angle = ray_angle;
		ray->is_facing_down = is_ray_facing_down(ray_angle);
		ray->is_facing_up = !ray->is_facing_down;
		ray->is_facing_right = is_ray_facing_right(ray_angle);
		ray->is_facing_left = !ray->is_facing_right;
		columnid++;
		angle_inc = main->raycast.fov_angle / main->raycast.num_of_rays;
		ray_angle += normalize_angle(angle_inc);
	}
}



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

bool	is_within_win(double x, double y)
{
	return (x >= 0 && x <= W_WIDTH && y >= 0 && y <= W_HEIGHT);
}

void	set_horz_wall_hit(t_main *main, int i)
{
	t_ray		*ray;
	t_impact	*horz;

	ray = &main->raycast.rays[i];
	horz = &ray->horz;
	horz->next_x = horz->x_intercept;
	horz->next_y = horz->y_intercept;
	if (ray->is_facing_up)
		horz->next_y--;
	while (is_within_win(horz->next_x, horz->next_y))
	{
		if (has_wall_at(main, horz->next_x, horz->next_y))
		{
			horz->wall_hit_x = horz->next_x;
			horz->wall_hit_y = horz->next_y;
			break ;
		}
		else
		{
			horz->next_x += horz->x_step;
			horz->next_y += horz->y_step;
		}
	}
	t_points	points;
	points.x0 = main->player.center_x;
	points.y0 = main->player.center_y;
	points.x1 = horz->wall_hit_x;
	points.y1 = horz->wall_hit_y;
	dda(main, &points);
}

void	find_horz_impact(t_main *main, int i)
{
	set_horz_intersection(main, i);
	set_horz_wall_hit(main, i);
}

void	set_wall_distance(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->raycast.num_of_rays)
	{
		find_horz_impact(main, i);
		i++;
	}
}

void	cast_rays(t_main *main)
{
	set_rays_angle(main);
	set_wall_distance(main);
	// draw_rays(main);
}
