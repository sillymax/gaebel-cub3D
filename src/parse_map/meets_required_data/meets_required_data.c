/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meets_required_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 04:17:55 by ychng             #+#    #+#             */
/*   Updated: 2024/07/16 06:23:35 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	meets_required_data(t_main *main, int fd)
{
	return (parse_data(main, fd) && \
			validate_2d_map(&main->mapdata));
}
