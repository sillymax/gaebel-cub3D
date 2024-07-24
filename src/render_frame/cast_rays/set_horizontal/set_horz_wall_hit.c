/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_horz_wall_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:56:17 by ychng             #+#    #+#             */
/*   Updated: 2024/07/25 01:45:27 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	while (is_within_2dmap_bounds(main, horz->next_x, horz->next_y))
	{
		if (has_wall_at(main, horz->next_x, horz->next_y))
		{
			horz->found_wall_hit = true;
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
}
