/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 05:35:55 by ychng             #+#    #+#             */
/*   Updated: 2024/07/17 05:37:34 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	has_wall_at(t_main *main, double x, double y)
{
	int	i;	
	int	j;

	i = floor(y / TILE_SIZE);
	j = floor(x / TILE_SIZE);
	return (main->mapdata.map2d[i][j] == '1');
}
