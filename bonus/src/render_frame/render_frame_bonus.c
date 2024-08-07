/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 05:28:06 by ychng             #+#    #+#             */
/*   Updated: 2024/08/07 17:30:59 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	clear_screen(t_main *main)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < main->mapdata.m_height)
	{
		x = 0;
		while (x < main->mapdata.m_width)
		{
			color = rgb(0, 0, 0);
			pixel_put(
				&main->minilibx.image,
				x,
				y,
				color
				);
			x++;
		}
		y++;
	}
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
	clear_screen(main);
	set_rays_properties(main);
	draw_walls(main);
	draw_map(main);
	draw_rays(main);
	draw_player(main);
	apply_keystates(main);
	img_to_win(main);
	return (PASS);
}
