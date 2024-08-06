/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_borders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 05:34:31 by ychng             #+#    #+#             */
/*   Updated: 2024/08/06 10:08:13 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	validate_left_and_right_border(t_mapdata *mapdata)
{
	int		col;
	int		row;
	char	curr_char;
	char	begin_and_end[2];

	row = 0;
	while (row < mapdata->rows)
	{
		ft_bzero(begin_and_end, 2);
		col = 0;
		while (col < mapdata->cols)
		{
			curr_char = mapdata->map2d[row][col];
			if (curr_char != ' ' && begin_and_end[0] == '\0')
				begin_and_end[0] = curr_char;
			else if (curr_char != ' ')
				begin_and_end[1] = curr_char;
			col++;
		}
		if (begin_and_end[0] != '1' || begin_and_end[1] != '1')
			return (return_with_error("got hole in left / right border."));
		row++;
	}
	return (PASS);
}

bool	validate_top_and_bottom_border(t_mapdata *mapdata)
{
	int		col;
	int		row;
	char	curr_char;
	char	begin_and_end[2];

	col = 0;
	while (col < mapdata->cols)
	{
		ft_bzero(begin_and_end, 2);
		row = 0;
		while (row < mapdata->rows)
		{
			curr_char = mapdata->map2d[row][col];
			if (curr_char != ' ' && begin_and_end[0] == '\0')
				begin_and_end[0] = curr_char;
			else if (curr_char != ' ')
				begin_and_end[1] = curr_char;
			row++;
		}
		if (begin_and_end[0] != '1' || begin_and_end[1] != '1')
			return (return_with_error("got hole in top / bottom border."));
		col++;
	}
	return (PASS);
}

bool	validate_rows(t_mapdata *mapdata)
{
	int		col;
	int		row;
	char	left_col;
	char	curr_col;
	char	right_col;

	row = 0;
	while (row < mapdata->rows)
	{
		col = 0;
		while (col < (mapdata->cols - 2))
		{
			left_col = mapdata->map2d[row][col];
			curr_col = mapdata->map2d[row][col + 1];
			right_col = mapdata->map2d[row][col + 2];
			if ((left_col == ' ' || right_col == ' ') && \
			ft_strchr("0NSEW", curr_col))
				return (return_with_error("got gap above / below a point."));
			col++;
		}
		row++;
	}
	return (PASS);
}

bool	validate_cols(t_mapdata *mapdata)
{
	int		col;
	int		row;
	char	top_col;
	char	curr_col;
	char	bottom_col;

	col = 0;
	while (col < mapdata->cols)
	{
		row = 0;
		while (row < (mapdata->rows - 2))
		{
			top_col = mapdata->map2d[row][col];
			curr_col = mapdata->map2d[row + 1][col];
			bottom_col = mapdata->map2d[row + 2][col];
			if ((top_col == ' ' || bottom_col == ' ') && \
			ft_strchr("0NSEW", curr_col))
				return (return_with_error("got gap left / right a point."));
			row++;
		}
		col++;
	}
	return (PASS);
}
