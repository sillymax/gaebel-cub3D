/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_2d_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 06:01:48 by ychng             #+#    #+#             */
/*   Updated: 2024/08/07 17:29:04 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

bool	pad_row(char **row, int max_col)
{
	int	curr_len;
	int	old_size;
	int	new_size;

	curr_len = ft_strlen(*row);
	old_size = (curr_len + 1) * sizeof(char);
	new_size = (max_col + 1) * sizeof(char);
	*row = ft_realloc(*row, old_size, new_size);
	if (*row == NULL)
		return (return_with_error("realloc failed."));
	ft_memset(*row + curr_len, ' ', max_col - curr_len);
	(*row)[max_col] = '\0';
	return (PASS);
}

bool	pad_2d_map(t_mapdata *mapdata)
{
	int		i;
	int		max_cols;
	char	**curr_row;

	i = 0;
	max_cols = get_max_cols(mapdata);
	while (i < mapdata->rows)
	{
		curr_row = &mapdata->map2d[i];
		if (ft_strlen(*curr_row) < max_cols)
		{
			if (pad_row(curr_row, max_cols) == FAIL)
				return (return_with_error("can't pad row."));
		}
		i++;
	}
	mapdata->cols = max_cols;
	return (PASS);
}
