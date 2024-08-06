/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keystates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 05:31:22 by ychng             #+#    #+#             */
/*   Updated: 2024/08/06 20:41:39 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	key_press(int keycode, t_main *main)
{
	if (!(keycode >= 0 && keycode <= KEY_COUNT))
		exit_with_error("can't support keys range.");
	if (main->key_states[keycode] == 0)
		main->key_states[keycode] = 1;
	return (PASS);
}

int	key_release(int keycode, t_main *main)
{
	if (!(keycode >= 0 && keycode <= KEY_COUNT))
		exit_with_error("can't support keys range.");
	if (main->key_states[keycode] == 1)
		main->key_states[keycode] = 0;
	return (PASS);
}

// int cmouse_move(t_main *main) {
// 	// mlx_mouse_get_pos(main->minilibx.mlx, main->minilibx.win, &main->player.mouse_x, &main->player.mouse_y);
// 	printf("mouse %d\n", main->player.mouse_x);
// 	mlx_mouse_show();
// 	// sleep(1000);
// 	return (0);
// }

void	apply_keystates(t_main *main)
{
	if (main->key_states[KEY_ESC])
	{
		cleanup(main);
		exit(0);
	}
	if (main->key_states[KEY_UP])
		move_forward_backward(main, 1);
	if (main->key_states[KEY_DOWN])
		move_forward_backward(main, -1);
	if (main->key_states[KEY_LEFT])
		rotate_player(main, -1);
	if (main->key_states[KEY_RIGHT])
		rotate_player(main, 1);
	if (main->key_states[KEY_W])
		move_forward_backward(main, 1);
	if (main->key_states[KEY_S])
		move_forward_backward(main, -1);
	if (main->key_states[KEY_D])
		move_left_right(main, 1);
	if (main->key_states[KEY_A])
		move_left_right(main, -1);
}
