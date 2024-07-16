/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 01:48:48 by ychng             #+#    #+#             */
/*   Updated: 2024/07/16 22:52:52y ychng            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_main	main;	

	if (argc != 2)
		exit_with_error("wrong number of args.");
	init_main(&main);
	parse_map(&main, argv[1]);
	set_initial_player_pos(&main);
	mlx_hook(main.minilibx.win, 2, 1L<<0, key_press, &main);
	mlx_hook(main.minilibx.win, 3, 1L<<1, key_release, &main);
	mlx_loop_hook(main.minilibx.mlx, render_frame, &main);
	mlx_loop(main.minilibx.mlx);
	return (PASS);
}
