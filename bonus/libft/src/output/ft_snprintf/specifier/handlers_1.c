/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:14:17 by ychng             #+#    #+#             */
/*   Updated: 2024/04/23 20:17:15 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handlechar(t_resultinfo *info, char c)
{
	write_tobuffer(info, c);
}

void	handlestring(t_resultinfo *info, char *str)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		write_tobuffer(info, *str);
		str++;
	}
}

void	handlepercent(t_resultinfo *info)
{
	write_tobuffer(info, '%');
}
