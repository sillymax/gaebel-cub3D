/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meets_required_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 04:17:55 by ychng             #+#    #+#             */
/*   Updated: 2024/08/06 10:22:53 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	meets_required_data(t_main *main, int fd)
{
	return (parse_data(main, fd) && \
	validate_2d_map(&main->mapdata));
}
