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


void	find_horz_impact(t_main *main, int i)
{
	set_horz_intersection(main, i);
	set_horz_wall_hit(main, i);
}

void	find_vert_impact(t_main *main, int i)
{
	set_vert_intersection(main, i);
	set_vert_wall_hit(main, i);
}

void	set_wall_distance(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->raycast.num_of_rays)
	{
		find_horz_impact(main, i);
		find_vert_impact(main, i);
		i++;
	}
}

void	cast_rays(t_main *main)
{
	set_rays_angle(main);
	set_wall_distance(main);
	// draw_rays(main);
}
