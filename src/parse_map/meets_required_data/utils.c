/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 05:54:23 by ychng             #+#    #+#             */
/*   Updated: 2024/07/16 06:07:44 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_max_cols(t_mapdata *mapdata)
{
	int	i;
	int	max_cols;

	i = 0;
	max_cols = ft_strlen(mapdata->map2d[0]);
	while (i < mapdata->rows)
	{
		if (max_cols < ft_strlen(mapdata->map2d[i]))
			max_cols = ft_strlen(mapdata->map2d[i]);
		i++;
	}
	return (max_cols);
}
