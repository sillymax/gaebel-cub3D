/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minilibx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 00:25:14 by ychng             #+#    #+#             */
/*   Updated: 2024/07/17 00:25:30 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_image(t_minilibx *minilibx)
{
	minilibx->image.img = mlx_new_image(minilibx->mlx, W_WIDTH, W_HEIGHT);
	minilibx->image.addr = mlx_get_data_addr( \
						minilibx->image.img, \
						&minilibx->image.bpp, \
						&minilibx->image.stride, \
						&minilibx->image.endian);
}

void	init_minilibx(t_minilibx *minilibx)
{
	minilibx->mlx = mlx_init();
	minilibx->win = mlx_new_window(minilibx->mlx, W_WIDTH, W_HEIGHT, "CUB3D");
	init_image(minilibx);
}