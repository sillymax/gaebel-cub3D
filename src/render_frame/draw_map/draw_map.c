/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:39:52 by ychng             #+#    #+#             */
/*   Updated: 2024/07/16 23:41:09 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_tile(t_image *image, int start_y, int start_x, int color)
{
	int	size;
	int	y;
	int	x;

	size = TILE_SIZE;
	y = start_y;
	while (y < (start_y + size))
	{
		x = start_x;
		while (x < (start_x + size))
		{
			pixel_put(image, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_at(t_main *main, int i, int j)
{
	int	color;

	if (main->mapdata.map2d[i][j] == M_WALL)
		color = rgb(255, 255, 255);
	else
		color = rgb(0, 0, 0);
	draw_tile(&main->minilibx.image, i * TILE_SIZE, j * TILE_SIZE, color);
}

void	draw_map(t_main *main)
{
	int	i;
	int	j;

	i = 0;
	while(i < main->mapdata.rows)
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
