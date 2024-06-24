/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:26:27 by ychng             #+#    #+#             */
/*   Updated: 2024/04/22 18:22:20 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, int n)
{
	int		copylen;
	char	*result;

	if (!str || n < 0)
		return (NULL);
	copylen = ft_strlen(str);
	if (copylen > n)
		copylen = n;
	result = malloc(sizeof(char) * (copylen + 1));
	if (!result)
		return (NULL);
	ft_strncpy(result, str, copylen);
	result[copylen] = '\0';
	return (result);
}
