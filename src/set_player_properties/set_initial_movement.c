/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_initial_movement.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:24:25 by ychng             #+#    #+#             */
/*   Updated: 2024/07/26 19:15:39 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_initial_movement(t_main *main)
{
	main->player.rotation_angle = PI / 2;
	main->player.rotation_speed = 1.5 * (PI / 180);
	main->player.move_speed = 2;
}
