/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vert_wall_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:09:59 by ychng             #+#    #+#             */
/*   Updated: 2024/07/25 20:32:46 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_vert_wall_hit(t_main *main, int i)
{
	t_ray		*ray;
	t_impact	*vert;
	double		test_next_x;

	ray = &main->raycast.rays[i];
	vert = &ray->vert;
	vert->found_wall_hit = false;
	vert->next_x = vert->x_intercept;
	vert->next_y = vert->y_intercept;
	while (is_within_2dmap_bounds(main, vert->next_x, vert->next_y))
	{
		test_next_x = vert->next_x;
		if (ray->is_facing_left)
			test_next_x--;
		if (has_wall_at(main, test_next_x, vert->next_y))
		{
			vert->found_wall_hit = true;
			vert->wall_hit_x = vert->next_x;
			vert->wall_hit_y = vert->next_y;
			break ;
		}
		vert->next_x += vert->x_step;
		vert->next_y += vert->y_step;
	}
}
