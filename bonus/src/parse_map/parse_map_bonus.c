/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 03:27:58 by ychng             #+#    #+#             */
/*   Updated: 2024/08/07 17:29:35 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_map_dimensions(t_main *main)
{
	main->mapdata.m_height = main->mapdata.rows * TILE_SIZE;
	main->mapdata.m_width = main->mapdata.cols * TILE_SIZE;
}

void	open_map(t_main *main, char *mapname)
{
	int	fd;

	fd = open(mapname, O_RDONLY);
	if (fd < 0)
		exit_with_error("can't open map.");
	if (meets_required_info(&main->mapinfo, fd) == FAIL)
	{
		close(fd);
		exit_with_error("wrong map info.");
	}
	if (meets_required_data(main, fd) == FAIL)
	{
		close(fd);
		exit_with_error("wrong map data.");
	}
	close(fd);
	set_map_dimensions(main);
}

void	parse_map(t_main *main, char *mapname)
{
	if (extension_is_cub(mapname) == FAIL)
		exit_with_error("wrong map extension.");
	open_map(main, mapname);
}
