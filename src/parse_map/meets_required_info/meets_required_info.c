/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meets_required_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 03:11:15 by ychng             #+#    #+#             */
/*   Updated: 2024/07/16 06:43:23 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	all_required_info_set(t_mapinfo *mapinfo)
{
	return (mapinfo->is_north_texture_set && \
			mapinfo->is_south_texture_set && \
			mapinfo->is_east_texture_set && \
			mapinfo->is_west_texture_set && \
			mapinfo->is_floorcolor_set && \
			mapinfo->is_ceilingcolor_set);
}

bool	set_required_info(t_mapinfo *mapinfo, char *line)
{
	char	*token;

	token = ft_strtok(line, " ");
	if (token)
	{
		return (set_direction_texture(mapinfo, token) && \
				set_color(mapinfo, token));
	}
	return (PASS);
}

bool	meets_required_info(t_mapinfo *mapinfo, int fd)
{
	char	*line;

	while (true)
	{
		if (all_required_info_set(mapinfo))
			break ;
		line = get_next_line(fd);
		if (!line)
			break ;
		else if (set_required_info(mapinfo, line) == FAIL)
		{
			free(line);
			return (false);
		}
		free(line);
	}
	return (all_required_info_set(mapinfo));
}
