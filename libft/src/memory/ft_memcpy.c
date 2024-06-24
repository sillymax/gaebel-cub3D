/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:29:49 by ychng             #+#    #+#             */
/*   Updated: 2024/04/22 17:31:39 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char	*destination;
	char	*source;

	if (!dest || !src)
		return (dest);
	destination = (char *)dest;
	source = (char *)src;
	while (size--)
		*destination++ = *source++;
	return (dest);
}
