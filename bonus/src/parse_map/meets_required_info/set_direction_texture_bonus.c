/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_direction_texture_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 03:13:56 by ychng             #+#    #+#             */
/*   Updated: 2024/08/07 17:29:28 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

bool	is_valid_path(char *path)
{
	return (!ft_strncmp(path, "./", 2) && ft_isalnum(path[2]));
}

bool	parse_texture(char **texture, bool *is_set)
{
	char	*path;

	if (texture && is_set)
	{
		path = ft_strtok(NULL, " ");
		if (!path)
			return (return_with_error("empty path."));
		if (!is_valid_path(path))
			return (return_with_error("wrong path format."));
		*texture = ft_strtrim(path, "\n");
		*is_set = true;
	}
	return (PASS);
}

bool	set_north_and_sound_texture(t_mapinfo *mapinfo, char *token)
{
	char	**texture;
	bool	*is_set;

	texture = NULL;
	is_set = NULL;
	if (ft_strcmp(token, "NO") == 0)
	{
		texture = &mapinfo->north_texture;
		is_set = &mapinfo->is_north_texture_set;
	}
	else if (ft_strcmp(token, "SO") == 0)
	{
		texture = &mapinfo->south_texture;
		is_set = &mapinfo->is_south_texture_set;
	}
	return (parse_texture(texture, is_set));
}

bool	set_east_and_west_texture(t_mapinfo *mapinfo, char *token)
{
	char	**texture;
	bool	*is_set;

	texture = NULL;
	is_set = NULL;
	if (ft_strcmp(token, "EA") == 0)
	{
		texture = &mapinfo->east_texture;
		is_set = &mapinfo->is_east_texture_set;
	}
	else if (ft_strcmp(token, "WE") == 0)
	{
		texture = &mapinfo->west_texture;
		is_set = &mapinfo->is_west_texture_set;
	}
	return (parse_texture(texture, is_set));
}

bool	set_direction_texture(t_mapinfo *mapinfo, char *token)
{
	return (set_north_and_sound_texture(mapinfo, token) && \
			set_east_and_west_texture(mapinfo, token));
}
