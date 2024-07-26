/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 05:28:38 by ychng             #+#    #+#             */
/*   Updated: 2024/07/26 19:17:02 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	move_forward_backward(t_main *main, int walk_direction)
{
	double	velocity;
	double	new_x;
	double	new_y;

	velocity = walk_direction * main->player.move_speed;
	new_x = main->player.center_x + cos(main->player.rotation_angle) * velocity;
	new_y = main->player.center_y + sin(main->player.rotation_angle) * velocity;
	if (!has_wall_at(main, new_x, new_y))
	{
		main->player.center_x = new_x;
		main->player.center_y = new_y;
	}
}

void	move_left_right(t_main *main, int side_direction)
{
	double	intensity;
	double	velocity;
	double	new_x;
	double	new_y;
	double	angle_offset;

	intensity = 0.5;
	velocity = side_direction * main->player.move_speed * intensity;
	angle_offset = PI / 2;
	new_x = main->player.center_x + cos(main->player.rotation_angle + angle_offset) * velocity;
	new_y = main->player.center_y + sin(main->player.rotation_angle + angle_offset) * velocity;
	if (!has_wall_at(main, new_x, new_y))
	{
		main->player.center_x = new_x;
		main->player.center_y = new_y;
	}
}
