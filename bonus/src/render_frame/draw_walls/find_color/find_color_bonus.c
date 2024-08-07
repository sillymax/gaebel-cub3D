/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_color_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 23:00:06 by ychng             #+#    #+#             */
/*   Updated: 2024/08/07 17:30:10 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

int	find_color(int color[3])
{
	int	red;
	int	green;
	int	blue;

	red = color[0];
	green = color[1];
	blue = color[2];
	return (rgb(red, green, blue));
}
