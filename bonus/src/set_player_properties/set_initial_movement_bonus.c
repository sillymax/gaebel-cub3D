/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_initial_movement_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:24:25 by ychng             #+#    #+#             */
/*   Updated: 2024/08/07 17:31:14 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	player_is_facing(t_main *main, char player)
{
	int	i;
	int	j;

	i = floor(main->player.center_y / TILE_SIZE);
	j = floor(main->player.center_x / TILE_SIZE);
	return (main->mapdata.map2d[i][j] == player);
}

void	set_initial_movement(t_main *main)
{
	if (player_is_facing(main, 'N'))
		main->player.rotation_angle = PI * 1.5;
	else if (player_is_facing(main, 'S'))
		main->player.rotation_angle = PI / 2;
	else if (player_is_facing(main, 'E'))
		main->player.rotation_angle = 0;
	else if (player_is_facing(main, 'W'))
		main->player.rotation_angle = PI;
	main->player.rotation_speed = 0.75 * (PI / 180);
	main->player.move_speed = 0.5;
}
