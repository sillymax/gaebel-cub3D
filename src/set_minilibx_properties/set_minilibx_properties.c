/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_minilibx_properties.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:47:43 by ychng             #+#    #+#             */
/*   Updated: 2024/07/25 16:55:19 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_image(t_main *main)
{
	main->minilibx.image.img = mlx_new_image( \
								main->minilibx.mlx, \
								main->mapdata.m_width, \
								main->mapdata.m_height);
	main->minilibx.image.addr = mlx_get_data_addr( \
									main->minilibx.image.img, \
									&main->minilibx.image.bpp, \
									&main->minilibx.image.stride, \
									&main->minilibx.image.endian);
}

void	set_minilibx(t_main *main)
{
	main->minilibx.mlx = mlx_init();
	main->minilibx.win = mlx_new_window( \
							main->minilibx.mlx, \
							main->mapdata.m_width, \
							main->mapdata.m_height, \
							"CUB3D");
}

void	set_minilibx_properties(t_main *main)
{
	set_minilibx(main);
	set_image(main);
}
