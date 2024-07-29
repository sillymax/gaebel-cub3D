/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rays_properties.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:02:03 by ychng             #+#    #+#             */
/*   Updated: 2024/07/29 23:47:42 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_hit_direction(t_main *main, int i)
{
	t_ray	*ray;

	ray = &main->raycast.rays[i];
	if (ray->was_hit_vert)
	{
		if (ray->ray_angle > (PI * 0.5) && ray->ray_angle < (PI * 1.5))
			main->raycast.rays[i].hit_direction = WEST;
		else
			main->raycast.rays[i].hit_direction = EAST;
	}
	else
	{
		if (ray->ray_angle > 0 && ray->ray_angle < PI)
			main->raycast.rays[i].hit_direction = SOUTH;
		else
			main->raycast.rays[i].hit_direction = NORTH;
	}
}

void	set_rays_impact(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->raycast.num_of_rays)
	{
		set_horz_impact(main, i);
		set_vert_impact(main, i);
		set_closest_impact(main, i);
		set_hit_direction(main, i);
		i++;
	}
}

void	set_rays_properties(t_main *main)
{
	set_rays_angle(main);
	set_rays_impact(main);
}
