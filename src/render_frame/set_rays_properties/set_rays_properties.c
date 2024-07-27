/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rays_properties.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:02:03 by ychng             #+#    #+#             */
/*   Updated: 2024/07/27 16:25:48 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_rays_impact(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->raycast.num_of_rays)
	{
		set_horz_impact(main, i);
		set_vert_impact(main, i);
		set_closest_impact(main, i);
		i++;
	}
}

void	set_rays_properties(t_main *main)
{
	set_rays_angle(main);
	set_rays_impact(main);
}
