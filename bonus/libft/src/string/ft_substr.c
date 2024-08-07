/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:31:37 by ychng             #+#    #+#             */
/*   Updated: 2024/04/22 18:34:48 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, int start, int len)
{
	int		strlen;
	int		substrlen;
	char	*result;

	if (!str || start < 0 || len < 0)
		return (NULL);
	strlen = ft_strlen(str);
	if (start >= strlen)
		return (NULL);
	substrlen = ft_min(strlen - start, len);
	result = malloc(sizeof(char) * (substrlen + 1));
	if (!result)
		return (NULL);
	ft_strncpy(result, str + start, substrlen);
	result[substrlen] = '\0';
	return (result);
}
