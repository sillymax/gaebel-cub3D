/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:41:29 by ychng             #+#    #+#             */
/*   Updated: 2024/07/17 00:27:50 by ychng            ###   ########.fr       */
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
	draw_player(main);
	img_to_win(main);
	return (PASS);
}
