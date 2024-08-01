/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 03:32:09 by ychng             #+#    #+#             */
/*   Updated: 2024/08/01 23:03:10 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	is_all_digits(char *str)
{
	int		i;
	bool	all_digits;

	i = 0;
	all_digits = true;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			all_digits = false;
			break ;
		}
		i++;
	}
	return (all_digits);
}

bool	is_in_rgb_range(char *str)
{
	int	value;

	value = ft_atoi(str);
	return (value >= 0 && value <= 255);
}

bool	validate_color_format(char *rgb)
{
	int		count;
	char	*token;

	count = 0;
	while (count < 3)
	{
		if (count == 0)
			token = ft_strtok(rgb, ",");
		else
			token = ft_strtok(NULL, ",");
		if (!(token && is_all_digits(token) && is_in_rgb_range(token)))
			return (PASS);
		count++;
	}
	token = ft_strtok(NULL, ",");
	if (token)
		return (FAIL);
	return (PASS);
}

bool	parse_color(int *color, bool *is_set)
{
	char	*rgb;
	char	*rgb_cpy;

	if (color && is_set)
	{
		rgb = ft_strtok(NULL, " ");
		if (rgb == NULL || rgb[0] == '\n')
			return (return_with_error("empty floor / ceiling color."));
		if (ft_strchr(rgb, '\n'))
			rgb_cpy = ft_strtrim(rgb, "\n");
		if (validate_color_format(rgb_cpy) == FAIL)
			return (return_with_error("wrong color format."));
		free(rgb_cpy);
		color[0] = ft_atoi(ft_strtok(rgb, ","));
		color[1] = ft_atoi(ft_strtok(NULL, ","));
		color[2] = ft_atoi(ft_strtok(NULL, ","));
		*is_set = true;
	}
	return (PASS);
}

bool	set_color(t_mapinfo *mapinfo, char *token)
{
	int		*color;
	bool	*is_set;

	color = NULL;
	is_set = NULL;
	if (ft_strcmp(token, "F") == 0)
	{
		color = mapinfo->floorcolor;
		is_set = &mapinfo->is_floorcolor_set;
	}
	else if (ft_strcmp(token, "C") == 0)
	{
		color = mapinfo->ceilingcolor;
		is_set = &mapinfo->is_ceilingcolor_set;
	}
	return (parse_color(color, is_set));
}
