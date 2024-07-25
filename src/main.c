/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 05:25:54 by ychng             #+#    #+#             */
/*   Updated: 2024/07/25 15:42:19 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_main	main;	

	if (argc != 2)
		exit_with_error("wrong number of args.");
	init_main(&main);
	parse_map(&main, argv[1]);
	set_player_properties(&main);
	set_raycast_properties(&main);
	mlx_hook(main.minilibx.win, 2, 1L<<0, key_press, &main);
	mlx_hook(main.minilibx.win, 3, 1L<<1, key_release, &main);
	mlx_loop_hook(main.minilibx.mlx, render_frame, &main);
	mlx_loop(main.minilibx.mlx);
	return (PASS);
}
