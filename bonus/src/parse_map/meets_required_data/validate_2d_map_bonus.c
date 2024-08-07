/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_2d_map_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 04:57:36 by ychng             #+#    #+#             */
/*   Updated: 2024/08/07 17:29:13 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	validate_chars(t_mapdata *mapdata)
{
	int		row;
	int		player_count;
	char	*curr_line;

	row = 1;
	player_count = 0;
	while (row < (mapdata->rows - 1))
	{
		curr_line = mapdata->map2d[row];
		if (!(ft_strspn(curr_line, " 01NSEW") == ft_strlen(curr_line)))
			return (return_with_error("got bad characters in map data."));
		if (ft_strpbrk(curr_line, "NSEW"))
		{
			player_count++;
			if (player_count > 1)
				return (return_with_error("got too many player."));
		}
		row++;
	}
	if (player_count == 0)
		return (return_with_error("no player."));
	return (PASS);
}

bool	validate_2d_map(t_mapdata *mapdata)
{
	if (mapdata->map2d == NULL)
		return (return_with_error("no mapdata."));
	return (validate_left_and_right_border(mapdata) && \
			validate_top_and_bottom_border(mapdata) && \
			validate_rows(mapdata) && \
			validate_cols(mapdata) && \
			validate_chars(mapdata));
}
