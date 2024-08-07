/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_raycast_properties_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:42:38 by ychng             #+#    #+#             */
/*   Updated: 2024/08/07 17:31:25 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	set_raycast_properties(t_main *main)
{
	main->raycast.fov_angle = 60 * (PI / 180);
	main->raycast.wall_strip_width = 1;
	main->raycast.num_of_rays = \
		(main->mapdata.m_width / main->raycast.wall_strip_width);
	main->raycast.rays = ft_calloc(sizeof(t_ray), main->raycast.num_of_rays);
}
