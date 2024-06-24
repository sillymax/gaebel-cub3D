/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:32:39 by ychng             #+#    #+#             */
/*   Updated: 2024/04/22 17:33:11 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t size)
{
	unsigned char	*destination;

	if (!dest)
		return (NULL);
	destination = (unsigned char *)dest;
	while (size--)
		*destination++ = (unsigned char)c;
	return (dest);
}
