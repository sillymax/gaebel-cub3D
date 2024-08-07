/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_minilibx_properties_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:47:43 by ychng             #+#    #+#             */
/*   Updated: 2024/08/07 17:31:09 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	set_image(t_main *main)
{
	main->minilibx.image.img = mlx_new_image(\
								main->minilibx.mlx, \
								main->mapdata.m_width, \
								main->mapdata.m_height);
	main->minilibx.image.addr = mlx_get_data_addr(\
									main->minilibx.image.img, \
									&main->minilibx.image.bpp, \
									&main->minilibx.image.stride, \
									&main->minilibx.image.endian);
}

void	set_minilibx(t_main *main)
{
	main->minilibx.mlx = mlx_init();
	main->minilibx.win = mlx_new_window(\
							main->minilibx.mlx, \
							main->mapdata.m_width, \
							main->mapdata.m_height, \
							"CUB3D");
}

char	*find_texture_path(t_main *main, int i)
{
	if (i == NORTH)
		return (main->mapinfo.north_texture);
	else if (i == SOUTH)
		return (main->mapinfo.south_texture);
	else if (i == EAST)
		return (main->mapinfo.east_texture);
	return (main->mapinfo.west_texture);
}

void	set_texture(t_main *main)
{
	int	i;
	int	size;

	size = TILE_SIZE;
	i = 0;
	main->minilibx.texture = ft_calloc(4, sizeof(t_image));
	while (i < 4)
	{
		main->minilibx.texture[i].img = mlx_xpm_file_to_image(\
										main->minilibx.mlx, \
										find_texture_path(main, i), \
										&size, &size);
		if (!main->minilibx.texture[i].img)
			exit_with_error("need a proper texture path.");
		main->minilibx.texture[i].addr = mlx_get_data_addr(\
										main->minilibx.texture[i].img, \
										&main->minilibx.texture[i].bpp, \
										&main->minilibx.texture[i].stride, \
										&main->minilibx.texture[i].endian);
		i++;
	}
}

void	set_minilibx_properties(t_main *main)
{
	set_minilibx(main);
	set_image(main);
	set_texture(main);
}
