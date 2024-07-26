/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 05:28:06 by ychng             #+#    #+#             */
/*   Updated: 2024/07/26 18:51:27 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	cast_rays(main);
	cast_wall_strips(main);
	draw_player(main);
	apply_keystates(main);
	img_to_win(main);
	return (PASS);
}
