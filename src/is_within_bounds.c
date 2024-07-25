/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_within_bounds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 01:40:22 by ychng             #+#    #+#             */
/*   Updated: 2024/07/25 17:34:58 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	is_within_win_bounds(t_main *main, int x, int y)
{
	return ((x >= 0 && x < main->mapdata.m_width) && \
			(y >= 0 && y < main->mapdata.m_height));
}

bool	is_within_2dmap_bounds(t_main *main, double x, double y)
{
	int	i;
	int	j;

	i = floor(y / TILE_SIZE);
	j = floor(x / TILE_SIZE);
	return ((i >= 0 && i < main->mapdata.rows) && \
			(j >= 0 && j < main->mapdata.cols));
}
