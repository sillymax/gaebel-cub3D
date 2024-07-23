/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 05:35:55 by ychng             #+#    #+#             */
/*   Updated: 2024/07/24 02:37:33 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	is_within_map_bounds(t_main *main, int i, int j)
{
	return ((i >= 0 && i < main->mapdata.rows) && \
			(j >= 0 && j < main->mapdata.cols));
}

bool	has_wall_at(t_main *main, double x, double y)
{
	int	i;	
	int	j;

	i = y / TILE_SIZE;
	j = x / TILE_SIZE;
	if (!is_within_map_bounds(main, i, j))
		return (true);
	return (main->mapdata.map2d[i][j] == '1');
}
