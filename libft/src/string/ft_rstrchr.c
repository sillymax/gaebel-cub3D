/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rstrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 07:57:59 by ychng             #+#    #+#             */
/*   Updated: 2024/04/22 17:43:22 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rstrchr(const char *str, int c)
{
	const char	*lastfound;

	lastfound = NULL;
	while (str && *str)
	{
		if (*str == (char)c)
			lastfound = str;
		str++;
	}
	return ((char *)lastfound);
}
