/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_horz_impact.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:23:56 by ychng             #+#    #+#             */
/*   Updated: 2024/07/27 16:24:15 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_horz_impact(t_main *main, int i)
{
	set_horz_intersection(main, i);
	set_horz_wall_hit(main, i);
}
