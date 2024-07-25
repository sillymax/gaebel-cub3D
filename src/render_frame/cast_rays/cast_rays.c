/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:02:03 by ychng             #+#    #+#             */
/*   Updated: 2024/07/25 17:04:12 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// void	find_horz_impact(t_main *main, int i)
// {
// 	// main->raycast.rays[i].ray_angle = PI/2;
// 	// main->raycast.rays[i].is_facing_down = is_ray_facing_down(main->raycast.rays[i].ray_angle);
// 	// main->raycast.rays[i].is_facing_up = !is_ray_facing_down(main->raycast.rays[i].ray_angle);
// 	// main->raycast.rays[i].is_facing_right = is_ray_facing_right(main->raycast.rays[i].ray_angle);
// 	// main->raycast.rays[i].is_facing_left = !is_ray_facing_right(main->raycast.rays[i].ray_angle);
// 	set_horz_intersection(main, i);
// 	set_horz_wall_hit(main, i);
// 	// t_points	points;

// 	// points.x0 = main->player.center_x;
// 	// points.y0 = main->player.center_y;
// 	// points.x1 = main->raycast.rays[i].horz.x_intercept;
// 	// points.y1 = main->raycast.rays[i].horz.y_intercept;
// 	// dda(main, &points);
// }


// void	find_vert_impact(t_main *main, int i)
// {
// 	// main->raycast.rays[i].ray_angle = PI*1.5;
// 	// main->raycast.rays[i].is_facing_down = is_ray_facing_down(main->raycast.rays[i].ray_angle);
// 	// main->raycast.rays[i].is_facing_up = !is_ray_facing_down(main->raycast.rays[i].ray_angle);
// 	// main->raycast.rays[i].is_facing_right = is_ray_facing_right(main->raycast.rays[i].ray_angle);
// 	// main->raycast.rays[i].is_facing_left = !is_ray_facing_right(main->raycast.rays[i].ray_angle);
// 	set_vert_intersection(main, i);
// 	set_vert_wall_hit(main, i);
// 	// t_points	points;

// 	// points.x0 = main->player.center_x;
// 	// points.y0 = main->player.center_y;
// 	// points.x1 = main->raycast.rays[i].vert.x_intercept;
// 	// points.y1 = main->raycast.rays[i].vert.y_intercept;
// 	// dda(main, &points);
// }

// double	distance_between_points(t_points *points)
// {
// 	long long	delta_x;
// 	long long	delta_y;

// 	delta_x = points->x1 - (long long)points->x0;
// 	delta_y = points->y1 - (long long)points->y0;
// 	return (sqrt((delta_x * delta_x) + (delta_y * delta_y)));
// }

// void	set_wall_distance(t_main *main)
// {
// 	int	i;

// 	i = 0;
// 	while (i < main->raycast.num_of_rays)
// 	{
// 		find_horz_impact(main, i);
// 		find_vert_impact(main, i);
// 		i++;
// 	}
// 	double		horz_hit_distance;
// 	double		vert_hit_distance;
// 	t_points	points;

// 	i = 0;
// 	while (i < main->raycast.num_of_rays)
// 	{
// 		if (main->raycast.rays[i].horz.found_wall_hit)
// 		{
// 			points.x0 = main->player.center_x;
// 			points.y0 = main->player.center_y;
// 			points.x1 = main->raycast.rays[i].horz.wall_hit_x;
// 			points.y1 = main->raycast.rays[i].horz.wall_hit_y;
// 			horz_hit_distance = distance_between_points(&points);
// 		}
// 		else
// 			horz_hit_distance = INT_MAX;
		
// 		if (main->raycast.rays[i].vert.found_wall_hit)
// 		{
// 			points.x0 = main->player.center_x;
// 			points.y0 = main->player.center_y;
// 			points.x1 = main->raycast.rays[i].vert.wall_hit_x;
// 			points.y1 = main->raycast.rays[i].vert.wall_hit_y;
// 			vert_hit_distance = distance_between_points(&points);
// 		}
// 		else
// 			vert_hit_distance = INT_MAX;
		
// 		if (horz_hit_distance < vert_hit_distance)
// 		{
// 			main->raycast.rays[i].wall_hit_x = main->raycast.rays[i].horz.wall_hit_x;
// 			main->raycast.rays[i].wall_hit_y = main->raycast.rays[i].horz.wall_hit_y;
// 			main->raycast.rays[i].distance = horz_hit_distance;
// 		}
// 		else
// 		{
// 			main->raycast.rays[i].wall_hit_x = main->raycast.rays[i].vert.wall_hit_x;
// 			main->raycast.rays[i].wall_hit_y = main->raycast.rays[i].vert.wall_hit_y;
// 			main->raycast.rays[i].distance = vert_hit_distance;
// 		}
		
// 		points.x0 = main->player.center_x;
// 		points.y0 = main->player.center_y;
// 		points.x1 = main->raycast.rays[i].wall_hit_x;
// 		points.y1 = main->raycast.rays[i].wall_hit_y;
// 		dda(main, &points);
// 		i++;
// 	}
// }

void	cast_rays(t_main *main)
{
	set_rays_angle(main);
	// set_wall_distance(main);
	draw_rays(main);
}
