/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rays_angle_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:53:46 by ychng             #+#    #+#             */
/*   Updated: 2024/08/07 17:30:47 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	set_rays_angle(t_main *main)
{
	int		columnid;
	t_ray	*ray;
	double	start_angle;
	double	angle_inc;
	double	ray_angle;

	columnid = 0;
	angle_inc = main->raycast.fov_angle / main->raycast.num_of_rays;
	start_angle = main->player.rotation_angle - (main->raycast.fov_angle / 2);
	ray_angle = start_angle;
	while (columnid < main->raycast.num_of_rays)
	{
		ray = &main->raycast.rays[columnid];
		ray->columnid = columnid;
		ray->ray_angle = normalized_angle(ray_angle);
		ray->is_facing_down = is_ray_facing_down(ray->ray_angle);
		ray->is_facing_up = !ray->is_facing_down;
		ray->is_facing_right = is_ray_facing_right(ray->ray_angle);
		ray->is_facing_left = !ray->is_facing_right;
		ray_angle += angle_inc;
		columnid++;
	}
}
