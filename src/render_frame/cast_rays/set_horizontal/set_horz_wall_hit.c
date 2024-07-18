/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_horz_wall_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:56:17 by ychng             #+#    #+#             */
/*   Updated: 2024/07/18 09:56:25 by ychng            ###   ########.fr       */
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
