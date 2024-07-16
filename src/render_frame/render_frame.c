/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:41:29 by ychng             #+#    #+#             */
/*   Updated: 2024/07/17 04:32:56 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	rotate_player(t_main *main, int turn_direction)
{
	main->player.rotation_angle += turn_direction * main->player.rotation_speed;
}

void	move_forward_backward(t_main *main, int walk_direction)
{
	int	velocity;
	int	new_x;
	int	new_y;

	velocity = walk_direction * main->player.move_speed;
	new_x = main->player.center_x + cos(main->player.rotation_angle) * velocity;
	new_y = main->player.center_y + sin(main->player.rotation_angle) * velocity;
	main->player.center_x = new_x;
	main->player.center_y = new_y;
}

void	move_left_right(t_main *main, int side_direction)
{
	int	velocity;
	int	new_x;

	velocity = side_direction * main->player.move_speed;
	new_x = main->player.center_x + velocity;
	main->player.center_x = new_x;
}

void	apply_keystates(t_main *main)
{

	if (main->key_states[UBUNTU_ESC])
	{
		mlx_destroy_window(main->minilibx.mlx, main->minilibx.win);
		exit(PASS);
	}
	if (main->key_states[UBUNTU_LEFT_ARROW])
		rotate_player(main, 1);
	if (main->key_states[UBUNTU_RIGHT_ARROW])
		rotate_player(main, -1);
	if (main->key_states[UBUNTU_W_KEY])
		move_forward_backward(main, 1);
	if (main->key_states[UBUNTU_S_KEY])
		move_forward_backward(main, -1);
	// if (main->key_states[UBUNTU_D_KEY])
	// 	move_left_right(main, 1);
	// if (main->key_states[UBUNTU_A_KEY])
	// 	move_left_right(main, -1);
}

void	img_to_win(t_main *main)
{
	mlx_put_image_to_window(
		main->minilibx.mlx, \
		main->minilibx.win, \
		main->minilibx.image.img, \
		0, 0);
}

int	render_frame(void *main)
{
	draw_map(main);
	draw_player(main);
	apply_keystates(main);
	img_to_win(main);
	return (PASS);
}
