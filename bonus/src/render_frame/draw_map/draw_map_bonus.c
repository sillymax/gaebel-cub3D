/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:39:52 by ychng             #+#    #+#             */
/*   Updated: 2024/08/07 17:29:47 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	draw_tile(t_image *image, int i, int j, int color)
{
	int	start_y;
	int	start_x;
	int	y;
	int	x;

	start_y = i * TILE_SIZE;
	start_x = j * TILE_SIZE;
	y = start_y;
	while (y < (start_y + TILE_SIZE))
	{
		x = start_x;
		while (x < (start_x + TILE_SIZE))
		{
			pixel_put(image, x * M_SCALE_FACTOR, y * M_SCALE_FACTOR, color);
			x++;
		}
		y++;
	}
}

void	draw_at(t_main *main, int i, int j)
{
	int	color;

	if (main->mapdata.map2d[i][j] == '1')
		color = rgb(255, 255, 255);
	else
		color = rgb(0, 0, 0);
	draw_tile(&main->minilibx.image, i, j, color);
}

void	draw_map(t_main *main)
{
	int	i;
	int	j;

	i = 0;
	while (i < main->mapdata.rows)
	{
		j = 0;
		while (j < main->mapdata.cols)
		{
			draw_at(main, i, j);
			j++;
		}
		i++;
	}
}
