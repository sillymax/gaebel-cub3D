/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:31:20 by ychng             #+#    #+#             */
/*   Updated: 2024/04/23 19:34:20 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *str, const char *accept)
{
	if (!str || !accept)
		return (NULL);
	while (*str)
	{
		if (ft_strchr(accept, *str) != NULL)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
