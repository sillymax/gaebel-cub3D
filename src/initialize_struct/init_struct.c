/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 02:08:16 by ychng             #+#    #+#             */
/*   Updated: 2024/07/17 01:17:33 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_mapinfo(t_mapinfo *mapinfo)
{
	mapinfo->north_texture = NULL;
	mapinfo->south_texture = NULL;
	mapinfo->east_texture = NULL;
	mapinfo->west_testure = NULL;
	mapinfo->floorcolor[0] = 0;
	mapinfo->floorcolor[1] = 0;
	mapinfo->floorcolor[2] = 0;
	mapinfo->ceilingcolor[0] = 0;
	mapinfo->ceilingcolor[1] = 0;
	mapinfo->ceilingcolor[2] = 0;
	mapinfo->is_north_texture_set = false;
	mapinfo->is_south_texture_set = false;
	mapinfo->is_west_texture_set = false;
	mapinfo->is_east_texture_set = false;
	mapinfo->is_floorcolor_set = false;
	mapinfo->is_ceilingcolor_set = false;
}

void	init_mapdata(t_mapdata *mapdata)
{
	mapdata->cols = 0;
	mapdata->rows = 0;
	mapdata->map2d = NULL;
}

void	init_player(t_player *player)
{
	player->center_x = 0;
	player->center_y = 0;
	player->topleft_x = 0;
	player->topleft_y = 0;
	player->rotation_angle = PI / 2;
	player->rotation_speed = 0.25 * (PI / 180);
}

void	init_main(t_main *main)
{
	init_mapinfo(&main->mapinfo);
	init_mapdata(&main->mapdata);
	init_minilibx(&main->minilibx);
	init_player(&main->player);
}
