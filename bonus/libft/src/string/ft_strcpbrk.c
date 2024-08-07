/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpbrk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:42:51 by ychng             #+#    #+#             */
/*   Updated: 2024/06/24 23:44:29 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpbrk(const char *str, const char *reject)
{
	if (!str || !reject)
		return (NULL);
	while (*str)
	{
		if (ft_strchr(reject, *str) == NULL)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
