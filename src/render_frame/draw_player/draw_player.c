/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:41:59 by ychng             #+#    #+#             */
/*   Updated: 2024/07/17 00:24:56 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_player_origin(t_main *main, int i, int j)
{
	main->player.center_y = i * TILE_SIZE + TILE_SIZE / 2;
	main->player.center_x = j * TILE_SIZE + TILE_SIZE / 2;
}

void	set_player_topleft(t_main *main)
{
	int	radius;

	radius = PLAYER_SIZE / 2;
	main->player.topleft_y = main->player.center_y - radius;
	main->player.topleft_x = main->player.center_x - radius;
}

void	find_player_pos(t_main *main)
{
	int	i;
	int	j;

	i = 0;
	while (i < main->mapdata.rows)	
	{
		j = 0;
		while (j < main->mapdata.cols)
		{
			if (ft_strchr("NSEW", main->mapdata.map2d[i][j]))
			{
				set_player_origin(main, i, j);
				set_player_topleft(main);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	draw_player_dot(t_main *main)
{
	int	y;
	int	x;	
	int	color;

	y = main->player.topleft_y;
	while (y < (main->player.topleft_y + PLAYER_SIZE))
	{
		x = main->player.topleft_x;
		while (x < (main->player.topleft_x + PLAYER_SIZE))
		{
			color = rgb(255, 0, 0);
			pixel_put(&main->minilibx.image, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_player(t_main *main)
{
	find_player_pos(main);
	draw_player_dot(main);
}
