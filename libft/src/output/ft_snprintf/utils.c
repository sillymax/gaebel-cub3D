/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:23:19 by ychng             #+#    #+#             */
/*   Updated: 2024/04/23 20:23:58 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	write_tobuffer(t_resultinfo *info, char c)
{
	if (info->size > 1)
	{
		*(info->buffer) = c;
		(info->buffer)++;
		(info->size)--;
	}
}
