/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:13:48 by ychng             #+#    #+#             */
/*   Updated: 2024/07/30 00:12:01 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_mapinfo(t_mapinfo *mapinfo)
{
	free(mapinfo->north_texture);
	free(mapinfo->south_texture);
	free(mapinfo->east_texture);
	free(mapinfo->west_texture);
}

void	free_mapdata(t_mapdata *mapdata)
{
	int	i;

	i = 0;
	while (i < mapdata->rows)
	{
		free(mapdata->map2d[i]);
		i++;
	}
	free(mapdata->map2d);
}

void	free_t_main(t_main *main)
{
	free_mapinfo(&main->mapinfo);
	free_mapdata(&main->mapdata);
	free(main->minilibx.texture);
	free(main->raycast.rays);
}
