/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vert_impact_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:24:26 by ychng             #+#    #+#             */
/*   Updated: 2024/08/07 17:30:37 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_vert_impact(t_main *main, int i)
{
	set_vert_intersection(main, i);
	set_vert_wall_hit(main, i);
}
