/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:36:14 by ychng             #+#    #+#             */
/*   Updated: 2024/08/07 17:30:54 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

double	normalized_angle(double angle)
{
	angle = fmod(angle, 2 * PI);
	if (angle < 0)
		angle += 2 * PI;
	return (angle);
}

bool	is_ray_facing_down(double angle)
{
	return (angle > 0 && angle < PI);
}

bool	is_ray_facing_right(double angle)
{
	return (angle < (PI * 0.5) || angle > (PI * 1.5));
}
