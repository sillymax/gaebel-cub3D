/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:31:43 by ychng             #+#    #+#             */
/*   Updated: 2024/06/24 21:51:38 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

typedef struct s_map
{
	size_t	rows;
	size_t	columns;
	char	**map2d;
}	t_map;

typedef struct s_main
{
	t_map	map;
}	t_main;

// bool	extension_is_cub()
// {
// 	while
// }

// void	parse_map()
// {
// 	if (extension_is_cub())
// 	if (meet_requirements())
// 	store_info();
// }

int main(int argc, char **argv)
{
	printf("%d", ft_strlen("hello"));
	// if (!(argc == 2))
	// 	return (write_error());
	// parse_map()
}
