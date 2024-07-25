/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minilibx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 00:25:14 by ychng             #+#    #+#             */
/*   Updated: 2024/07/25 16:53:18 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_image(t_minilibx *minilibx)
{
	minilibx->image.img = NULL;
	minilibx->image.addr = NULL;
	minilibx->image.bpp = 0;
	minilibx->image.stride = 0;
	minilibx->image.endian = 0;
}

void	init_minilibx(t_minilibx *minilibx)
{
	minilibx->mlx = NULL;
	minilibx->win = NULL;
	init_image(minilibx);
}
