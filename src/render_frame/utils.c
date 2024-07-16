/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:40:34 by ychng             #+#    #+#             */
/*   Updated: 2024/07/16 23:40:47 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	pixel_put(t_image *image, int x, int y, int color)
{
	int		y_bytes;
	int		x_bytes;
	char	*dst;

	y_bytes = y * image->stride;
	x_bytes = x * (image->bpp / 8);
	dst = image->addr + y_bytes + x_bytes; 
	*(int *)dst = color;
}
