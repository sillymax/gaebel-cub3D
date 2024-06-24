/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:34:28 by ychng             #+#    #+#             */
/*   Updated: 2024/04/22 18:46:32 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t originalsize, size_t newsize)
{
	void	*result;
	size_t	copysize;

	if (!ptr)
		return (malloc(newsize));
	if (newsize == 0)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(newsize);
	if (!result)
		return (NULL);
	copysize = ft_min(originalsize, newsize);
	ft_memcpy(result, ptr, copysize);
	free(ptr);
	return (result);
}
