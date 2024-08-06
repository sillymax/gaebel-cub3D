/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_initial_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 03:38:33 by ychng             #+#    #+#             */
/*   Updated: 2024/08/06 10:04:49 by ghwa             ###   ########.fr       */
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
	double	radius;

	radius = PLAYER_SIZE / 2;
	main->player.topleft_y = main->player.center_y - radius;
	main->player.topleft_x = main->player.center_x - radius;
}

void	set_initial_position(t_main *main)
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
